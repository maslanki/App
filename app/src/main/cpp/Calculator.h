#ifndef SOUNDAPP_CALCULATOR_H
#define SOUNDAPP_CALCULATOR_H
#include "../jni/c_api.h"
class Calculator {
public:
    Calculator();
    int number;
    int plusOne();
    int plusOneByTensorFlow();

private:
    TfLiteModel* model;
    TfLiteInterpreter* interpreter;

};


#endif //SOUNDAPP_CALCULATOR_H
