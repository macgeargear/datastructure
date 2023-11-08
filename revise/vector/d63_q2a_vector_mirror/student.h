#ifndef __STUDENT_H_
#define __STUDENT_H_

#include "vector.h"

template <typename T>
void CP::vector<T>::mirror() {
    // write your code here
    ensureCapacity(mSize * 2);
    for (int i = 0; i < mSize; i++) {
        mData[2 * mSize - i - 1] = mData[i];
    }
    mSize *= 2;
}

#endif
