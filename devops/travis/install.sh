#!/usr/bin/env sh
sudo apt-get install -y openmpi-bin libopenmpi-dev
python --version
python -m pip install --upgrade pip
python -m pip install -r requirements.txt
python -m pip install coverage
