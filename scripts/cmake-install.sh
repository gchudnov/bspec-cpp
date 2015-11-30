#!/usr/bin/env bash
set -e

SH_FILE='cmake-3.4.0-Linux-x86_64.sh'

wget http://www.cmake.org/files/v3.4/${SH_FILE}
chmod a+x ${SH_FILE}
sudo ./${SH_FILE} --skip-license --prefix=/usr/local
export PATH=/usr/local/bin:$PATH

cmake --version
