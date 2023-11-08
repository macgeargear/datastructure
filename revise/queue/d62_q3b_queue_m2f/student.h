#ifndef __STUDENT_H_
#define __STUDENT_H_

#include <algorithm>
#include <iostream>

#include "queue.h"

template <typename T>
void CP::queue<T>::move_to_front(size_t pos) {
    // your code here
    T tmp = mData[(mFront + pos) % mCap];
    for (int i = pos; i < mSize; i++) {
        mData[(mFront + i) % mCap] = mData[(mFront + i + 1) % mCap];
    }

    mData[(mFront - 1) % mCap] = tmp;
    mFront = (mFront - 1) % mCap;
}

#endif
