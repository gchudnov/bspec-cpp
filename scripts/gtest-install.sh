#!/usr/bin/env bash

curl -OL https://googletest.googlecode.com/files/gtest-1.7.0.zip
unzip -q gtest-1.7.0.zip

# libc++ must be built
if [ -n "$CLANG_VERSION" ]; then CXX_FLAGS="${CXX_FLAGS} -stdlib=libc++ -I/usr/include/c++/v1/"; fi
if [ -n "$CLANG_VERSION" ]; then CXX_LINKER_FLAGS="${CXX_FLAGS} -L/usr/lib/ -lc++abi"; fi

mkdir gtest-1.7.0/build
(cd gtest-1.7.0/build && cmake .. -DCMAKE_CXX_FLAGS="${CXX_FLAGS}" -DCMAKE_EXE_LINKER_FLAGS="${CXX_LINKER_FLAGS}")
make -C gtest-1.7.0/build -j2

sudo cp -R gtest-1.7.0/include /usr
sudo cp -r gtest-1.7.0/build/libg* /usr/lib/
