#!/usr/bin/env python3

import ndsb, os, sys, pathlib
from github import Github
from github.GithubException import UnknownObjectException

NDSB_DEBUG = os.getenv("NDSB_DEBUG", "").lower() == "true"
NDSB_VAULT_URL = os.getenv("NDSB_VAULT_URL")
NDSB_USERNAME = os.getenv("NDSB_USERNAME", "")
NDSB_CLIENT_ID = os.getenv("NDSB_CLIENT_ID", "")
NDSB_CLIENT_SECRET = os.getenv("NDSB_CLIENT_SECRET", "")
NDSB_PASSWORD = os.getenv("NDSB_PASSWORD", "")
NDSB_VAULT_KEY = os.getenv("NDSB_VAULT_KEY", "")
NDSB_FIRE_AT_STRANGERS = os.getenv("NDSB_FIRE_AT_STRANGERS", "").lower() == "true"
try:
    TRAVIS_PULL_REQUEST = int(os.getenv("TRAVIS_PULL_REQUEST", False))
except:
    TRAVIS_PULL_REQUEST = False
TRAVIS_REPO_SLUG = os.getenv("TRAVIS_REPO_SLUG", "")
GITHUB_TOKEN = os.getenv("GITHUB_TOKEN", "")

if not (NDSB_USERNAME or NDSB_VAULT_KEY):
    raise Exception("No authentication method provided.")

if NDSB_USERNAME:
    print("Authenticating with login")
    NDSB_VAULT_KEY = ndsb.aim(
        NDSB_VAULT_URL, NDSB_CLIENT_ID, NDSB_CLIENT_SECRET, NDSB_USERNAME, NDSB_PASSWORD
    )
else:
    print("Authenticating with key")

print("Start build artifact script.")
sys.path.insert(0, str(pathlib.Path(os.getcwd()) / "tests"))
data = ndsb.thaw()
print(f"Found {len(data)} artifacts.")

beam = ndsb.artificer(data)
print(f"Beaming artifact archive to '{NDSB_VAULT_URL}'")
try:
    response = beam.fire(
        NDSB_VAULT_URL, NDSB_VAULT_KEY, fire_at_strangers=NDSB_FIRE_AT_STRANGERS
    )
finally:
    if NDSB_DEBUG:
        # Re-freeze the data to re-use them
        for datum in data:
            datum.freeze()

beam_id = response["id"]

print(f"Beam etched with id {beam_id}")

if not TRAVIS_REPO_SLUG:
    print(f"Invalid repository slug '{TRAVIS_REPO_SLUG}', cancelling build report.")
    exit(1)

if not TRAVIS_PULL_REQUEST:
    print("Exiting without build artifact report, not a pull request.")
    exit(0)

print(f"Posting build artifact report to {TRAVIS_REPO_SLUG}#{TRAVIS_PULL_REQUEST}.")
gh = Github(GITHUB_TOKEN)
user = gh.get_user()
print(f"Connected to Github as '{user.name}'")

try:
    repo = gh.get_repo(TRAVIS_REPO_SLUG)
except UnknownObjectException:
    raise Exception(f"Repository '{TRAVIS_REPO_SLUG}' not found") from None
try:
    pr = repo.get_pull(TRAVIS_PULL_REQUEST)
except UnknownObjectException:
    raise Exception(f"Pull request {TRAVIS_PULL_REQUEST} not found.") from None

report_title = "# Build artifact report"


def render_artifact_report(artifacts):
    return report_title + "\n\n" + "\n".join(a.view() for a in artifacts)


def edit_comment(comment, artifacts):
    comment.edit(render_artifact_report(artifacts))


def post_comment(pr, artifact):
    pr.create_issue_comment(render_artifact_report(artifacts))


artifacts = data

for comment in pr.get_issue_comments():
    if comment.user.id == user.id and comment.body.split("\n")[0] == report_title:
        print("Editing existing comment", comment.id)
        edit_comment(comment, artifacts)
        break
else:
    print("Posting new comment")
    post_comment(pr, artifacts)

print("Artifact upload & report complete.")
