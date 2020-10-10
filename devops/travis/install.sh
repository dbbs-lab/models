#!/usr/bin/env sh
sudo apt-get install -y openmpi-bin libopenmpi-dev
pip3 install --upgrade pip
pip3 install -r requirements.txt
pip3 install coverage
