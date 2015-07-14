#!/usr/bin/env bash
set -e

# http://askubuntu.com/questions/309786/llvm-and-clang-installation-on-ubuntu
sudo ln -sf -T /usr/bin/llvm-config-3.7 /usr/local/bin/llvm-config

# https://llvm.org/bugs/show_bug.cgi?id=23352
SHARE_LLVM_CMAKE_DIR=$(dirname `find / -name LLVMConfig.cmake 2>/dev/null`)
sudo mkdir -p /usr/lib/llvm-3.7/share/llvm
sudo ln -sf -T "${SHARE_LLVM_CMAKE_DIR}" /usr/lib/llvm-3.7/share/llvm/cmake
