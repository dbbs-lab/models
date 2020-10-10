#!/usr/bin/env python3

import ndsb, os, sys, pathlib
from github import Github
from github.GithubException import UnknownObjectException

print("Start build artifact script.")
sys.path.insert(0, str(pathlib.Path(os.getcwd()) / "tests"))
pickles = ndsb.thaw()
print(f"Found {len(pickles)} artifacts.")

try:
    beam = ndsb.artificer(pickles)
    url = os.getenv("NDSB_VAULT_URL")
    print(f"Beaming artifact archive to '{url}'")
    response = beam.fire(url, os.getenv("NDSB_VAULT_KEY"))
    beam_id = response["id"]
    print(f"Beam etched with id {beam_id}")

TRAVIS_PULL_REQUEST = os.getenv("TRAVIS_PULL_REQUEST", 1)
TRAVIS_SLUG = os.getenv("TRAVIS_SLUG", "Helveg/test-bot")

if not TRAVIS_PULL_REQUEST:
    print("Exiting without build artifact report, not a pull request.")
    exit(0)

print(f"Posting build artifact report to {TRAVIS_SLUG}#{TRAVIS_PULL_REQUEST}.")
report_title = "# Build artifact report"

def render_artifact_report(artifacts):
    return report_title + "\n\n" + "\n".join(a.view() for a in artifacts)

def edit_comment(comment, artifacts):
    comment.edit(render_artifact_report(artifacts))

def post_comment(pr, artifact):
    pr.create_issue_comment(render_artifact_report(artifacts))

artifacts = pickles
gh = Github(os.getenv("GITHUB_TOKEN", ""))
print(f"Connected to Github as '{gh.get_user().name}'")
try:
    repo = gh.get_repo(TRAVIS_SLUG)
except UnknownObjectException:
    raise Exception(f"Repository '{TRAVIS_SLUG}' not found") from None
try:
    pr = repo.get_pull(TRAVIS_PULL_REQUEST)
except UnknownObjectException:
    raise Exception(f"Pull request {TRAVIS_PULL_REQUEST} not found.") from None

uid = gh.get_user().id
for comment in pr.get_issue_comments():
    if comment.user.id == uid and comment.body.split("\n")[0] == report_title:
        print("Editing existing comment", comment.id)
        edit_comment(comment, artifacts)
        break
else:
    print("Posting new comment")
    post_comment(pr, artifacts)

print("Artifact upload & report complete.")
