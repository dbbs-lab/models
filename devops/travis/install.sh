#!/usr/bin/env sh
sudo apt-get update
sudo apt-get install -y python3-rtree build-essential cmake cython libgsl-dev libltdl-dev libncurses-dev libreadline-dev openmpi-bin libopenmpi-dev
python --version
python -m pip install --upgrade pip
python -m pip install -r requirements.txt
python -m pip install coverage
