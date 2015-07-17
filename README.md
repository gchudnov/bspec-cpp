# bspec-cpp [![Build Status](https://travis-ci.org/gchudnov/bspec-cpp.svg?branch=master)](https://travis-ci.org/gchudnov/bspec-cpp)

> A C++ library for structuring business rules.

## Overview

[Structuring and validating business rules in JavaScript](https://medium.com/@gchudnov/structuring-and-validating-business-rules-in-javascript-fbaa1019902a)

## Usage
The essential part of the library is a *specification* -- an object with the following properties:
* it can be combined with other *specification*-objects using `.And()`, `.Or()` and `.Not()` methods to form a composite specification and express more complex rules.
* it implements `is_satisfied_by` method -- a predicate that determines whether a *candidate* object does or does not satisfy some criteria.

To create a specification:
* create a new class that inherits `basic_spec<T>`.
* override the `clone` method to allow copying.
* override the `is_satisfied_by` method.

## API

### .And(otherSpec)
the _and_ of a set of specifications is *true* if and only if all of its operands are *true*. 
```c++
auto spec = spec1.And(spec2);
```

### .Or(otherSpec)
the _or_ of a set of specifications is *true* if and only if one or more of its operands is *true*
```c++
autp spec = spec1.Or(spec2);
```

### .Not()
_not_ negates the specification
```c++
var spec = spec1.Not();
```

### .is_satisfied_by(candidate)
checks whether some _candidate_ object satisfies the specification.
```c++
  auto result = spec.is_satisfied_by(obj);
  
  // `result` true|false value
  // should throw an exception in case of an error
```

### Tested compilers

* Linux (x86/64)
   * GCC 5.1
   * Clang 3.7

### Installation

This is a header only library, in order to use it make the bspec-`include` directory available to your project and include the header file in your source code:

```c++
#include "bspec/spec.h"
``` 

### Building Tests & Examples

This project tests and examples use the Cross-platform Make ([CMake](http://www.cmake.org/)) build system.
Tests depend on [Google Test Framework](https://code.google.com/p/googletest/). gtest-1.7.0 is recommended.

#### Linux

The recommended way is to create 'out of source' build:

```bash
mkdir build
cd build
cmake ..
make
```

## Contact

[Grigoriy Chudnov] (mailto:g.chudnov@gmail.com)


## License

Distributed under the [The MIT License (MIT)](https://github.com/gchudnov/bspec-cpp/blob/master/LICENSE).
