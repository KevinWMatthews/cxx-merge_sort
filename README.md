# Merge Sort

A naive implementation of the Merge Sort algorithm.


## Background

This is a hands-on approach to learning. Don't just read about it; do it.


## Prerequisites

  * CMake 3.5.1
  * g++
  * gtest


## Setup

An out-of-tree build is recommended and is simple to do with CMake:
```bash
$ mkdir merge_sort && cd merge_sort
$ git clone https://github.com/KevinWMatthews/cxx-merge_sort
$ mkdir build_merge_sort_release build_merge_sort_debug
```

For release builds,
```bash
$ cd merge_sort/build_merge_sort_release
$ cmake ../merge_sort -DCMAKE_BUILD_TYPE=Release
```

For debug builds,
```bash
$ cd merge_sort/build_merge_sort_debug
$ cmake ../merge_sort -DCMAKE_BUILD_TYPE=Debug
```

## Build

```bash
$ cd merge_sort/build_merge_sort_<build_type>
$ make
```


## Tests

Unit tests can be compiled or skipped using a CMake option:
```bash
$ cmake ../merge_sort -DCOMPILE_UNIT_TESTS=On
$ cmake ../merge_sort -DCOMPILE_UNIT_TESTS=Off
```
or using `cmake-gui`, `ccmake`, etc.
Tests *are* compiled by default.

Tests are then compiled along with production code:
```bash
$ make
```

Run all tests using CTest:
```bash
$ ctest
# or
$ make test         # Does not recompile source!
```

Individual test executables are located in `bin/`. These give verbose output and options.
