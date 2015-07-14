#!/usr/bin/env bash
set -e

wget http://www.cmake.org/files/v3.2/cmake-3.2.3-Linux-x86_64.sh
chmod a+x cmake-3.2.3-Linux-x86_64.sh
sudo ./cmake-3.2.3-Linux-x86_64.sh --skip-license --prefix=/usr/local
export PATH=/usr/local/bin:$PATH

cmake --version
