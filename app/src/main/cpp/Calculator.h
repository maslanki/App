#ifndef SOUNDAPP_CALCULATOR_H
#define SOUNDAPP_CALCULATOR_H

#include "../jni/c_api.h"
#include "../jni/common.h"
#include <android/log.h>

class Calculator {
public:
    Calculator();
    int number;
    int plusOne();
    TfLiteModel * model;
    TfLiteInterpreterOptions* options;
    TfLiteInterpreter * interpreter;
    TfLiteTensor * input_tensor;
    const TfLiteTensor * output_tensor;
    int plusOneByTensorFlow(){
         model = TfLiteModelCreateFromFile("modeladd10.tflite");
         options = TfLiteInterpreterOptionsCreate();
         interpreter = TfLiteInterpreterCreate(model, options);
       // TfLiteInterpreterAllocateTensors(interpreter);

//        TfLiteTensor* input_tensor = TfLiteInterpreterGetInputTensor(interpreter, 0);
////float* input = 0;
//        float input[49] = { 0.0 };
//        TfLiteTensorCopyFromBuffer(input_tensor, input, 49 * sizeof(float));
//
//        TfLiteInterpreterInvoke(interpreter);
//
//        float output[49];
//
//        const TfLiteTensor* output_tensor = TfLiteInterpreterGetOutputTensor(interpreter, 14);
//        TfLiteTensorCopyToBuffer(output_tensor, output, sizeof(float));
//
//
//        TfLiteInterpreterDelete(interpreter);
//        TfLiteInterpreterOptionsDelete(options);
//        TfLiteModelDelete(model);
//        number = output[0];

    }
};


#endif //SOUNDAPP_CALCULATOR_H
