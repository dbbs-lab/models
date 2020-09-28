#!/usr/bin/env sh
wget https://neuron.yale.edu/ftp/neuron/versions/v7.7/nrn-7.7.x86_64-linux.deb
sudo dpkg -i nrn-7.7.x86_64-linux.deb
export PYTHONPATH=/usr/local/nrn/lib/python:$PYTHONPATH
sudo apt-get install -y python3-rtree build-essential cmake cython libgsl-dev libltdl-dev libncurses-dev libreadline-dev openmpi-bin libopenmpi-dev
pip3 install --upgrade pip
pip3 install -r requirements.txt
pip3 install coverage
