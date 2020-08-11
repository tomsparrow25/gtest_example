#include "CodeCoverage.h"

void Sum::setAValue(int A) {
    _A = A;
}

void Sum::setBValue(int B) {
    _B = B;
}

int Sum::executeSum(void) {
    return _A + _B;
}