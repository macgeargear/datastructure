#ifndef __STUDENT_H_
#define __STUDENT_H_
#include "vector.h"
template <typename T>
void CP::vector<T>::mirror() {
    // write your code here
    T* tmp = new T[2 * mSize];
    for (size_t i = 0; i < mSize; i++) {
        tmp[i] = mData[i];
        tmp[2 * mSize - i - 1] = mData[i];
    }
    delete[] mData;
    mData = tmp;
    mSize = 2 * mSize;
    mCap = mSize;
}
#endif
