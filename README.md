# factorial_gtest_example

## Install googletest library on you linux host
```$ git clone https://github.com/google/googletest.git
$ cd googletest
$ git checkout tags/v1.10.x -b v1.10.x
$ cd ..
$ mkdir buildgtest
$ cd buildgtest
$ cmake ../googletest
$ make
$ sudo make install
```

## Clone unit test example

```$ git clone https://github.com/giangtqh/factorial_gtest_example.git
$ cd factorial_gtest_example
$ make
$ ./unittest
[==========] Running 2 tests from 1 test suite.
[----------] Global test environment set-up.
[----------] 2 tests from FactorialTest
[ RUN      ] FactorialTest.HandlesZeroInput
[       OK ] FactorialTest.HandlesZeroInput (0 ms)
[ RUN      ] FactorialTest.HandlesPositiveInput
[       OK ] FactorialTest.HandlesPositiveInput (0 ms)
[----------] 2 tests from FactorialTest (0 ms total)

[----------] Global test environment tear-down
[==========] 2 tests from 1 test suite ran. (0 ms total)
[  PASSED  ] 2 tests.
```
