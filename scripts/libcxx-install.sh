#!/usr/bin/env bash
set -ex

WORK_DIR=$(pwd)

svn --quiet co http://llvm.org/svn/llvm-project/libcxxabi/trunk libcxxabi
svn --quiet co http://llvm.org/svn/llvm-project/libcxx/trunk libcxx

# libc++abi
mkdir libcxxabi/build
(cd libcxxabi/build && cmake .. -DLIBCXXABI_LIBCXX_PATH="$WORK_DIR/libcxx" -DLLVM_CONFIG=/usr/local/bin/llvm-config)
make -C libcxxabi/build -j2

sudo cp -r libcxxabi/build/lib/libc++abi.so.1.0 /usr/lib/
sudo ln -sf /usr/lib/libc++abi.so.1.0 /usr/lib/libc++abi.so
sudo ln -sf /usr/lib/libc++abi.so.1.0 /usr/lib/libc++abi.so.1

sudo mkdir /usr/include/c++/v1
sudo cp -r libcxxabi/include/* /usr/include/c++/v1/

# libc++
mkdir libcxx/build
(cd libcxx/build && cmake .. -DLIBCXX_CXX_ABI=libcxxabi -DLIBCXX_CXX_ABI_INCLUDE_PATHS="$WORK_DIR/libcxxabi/include")
make -C libcxx/build cxx -j2
sudo cp libcxx/build/lib/libc++.so.1.0 /usr/lib/
sudo ln -sf /usr/lib/libc++.so.1.0 /usr/lib/libc++.so
sudo ln -sf /usr/lib/libc++.so.1.0 /usr/lib/libc++.so.1

sudo cp -r libcxx/include/* /usr/include/c++/v1/
