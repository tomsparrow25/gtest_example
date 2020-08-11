# factorial_gtest_example

## Install googletest library on you linux host
```
$ git clone https://github.com/google/googletest.git
$ cd googletest
$ git checkout tags/v1.10.x -b v1.10.x
$ cd ..
$ mkdir buildgtest
$ cd buildgtest
$ cmake -DBUILD_SHARED_LIBS=ON ../googletest
$ make
$ sudo make install
```

## Clone unit test example

```
$ git clone https://github.com/giangtqh/gtest_example.git
$ cd gtest_example
# Build Factorial application
$ mkdir build
$ cd build && cmake ..
$ ./Factorial
```
## Build Factorial test 

```
$ cd test
$ mkdir build
$ cd build && cmake ..
$ make FactorialTest
$ ./FactorialTest
```

## Build CodeCoverage

```
$ cd test
$ mkdir build
$ cd build && cmake ..
$ make TestCodeCoverage
$ ./FactorialTest
```

## Generate code coverage report for CodeCoverage

```
$ cd /home/u16/ghome/gtest_example/test/build
$ make gcov
$ make lcov
# see report in /home/u16/ghome/gtest_example/test/build/lcoverage/index.html
```