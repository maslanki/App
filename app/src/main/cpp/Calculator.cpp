#include "Calculator.h"


Calculator::Calculator(){
    number = 0;
}

int Calculator::plusOne() {
    return ++number;
}

int Calculator::plusOneByTensorFlow() {
    return number;
}