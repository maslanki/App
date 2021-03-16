#ifndef SOUNDAPP_UTILS_H
#define SOUNDAPP_UTILS_H

template <typename K>
void fillArrayWithZeros(K *data, int32_t length) {

    size_t bufferSize = length * sizeof(K);
    memset(data, 0, bufferSize);
}
#endif //SOUNDAPP_UTILS_H
