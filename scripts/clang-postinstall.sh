#!/usr/bin/env bash

# http://askubuntu.com/questions/309786/llvm-and-clang-installation-on-ubuntu
ln -sf -T /usr/bin/llvm-config-3.7 /usr/local/bin/llvm-config

# https://llvm.org/bugs/show_bug.cgi?id=23352
mkdir -p /usr/lib/llvm-3.7/share/llvm
ln -sf -T /usr/share/llvm-3.7/cmake /usr/lib/llvm-3.7/share/llvm/cmake
