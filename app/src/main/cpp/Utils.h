//
// Created by User on 14.03.2021.
//

#ifndef SOUNDAPP_UTILS_H
#define SOUNDAPP_UTILS_H

#include "../../../../../../../AppData/Local/Android/Sdk/ndk/21.1.6352462/toolchains/llvm/prebuilt/windows-x86_64/lib64/clang/9.0.8/include/opencl-c-base.h"
#include "../../../../../../../AppData/Local/Android/Sdk/ndk/21.1.6352462/toolchains/llvm/prebuilt/windows-x86_64/sysroot/usr/include/c++/v1/cstdint"

template <typename K>
void fillArrayWithZeros(K *data, int32_t length) {

    size_t bufferSize = length * sizeof(K);
    memset(data, 0, bufferSize);
}
#endif //SOUNDAPP_UTILS_H
