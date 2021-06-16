#include "Calculator.h"

Calculator::Calculator(){
    //model* = TfLiteModelCreateFromFile("");
    //*interpreter = TfLiteInterpreterCreate(model);
    //TfLiteInterpreterAllocateTensors(interpreter);
    number = 0;
}

int Calculator::plusOne() {
    return ++number;
}

int Calculator::plusOneByTensorFlow() {
    return number;
}