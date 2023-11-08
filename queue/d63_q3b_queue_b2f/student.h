#ifndef __STUDENT_H_
#define __STUDENT_H_

#include <algorithm>
#include <iostream>

#include "queue.h"

template <typename T>
void CP::queue<T>::back_to_front() {
    // write your code here
    mData[(mFront - 1) % mCap] = back();
    mFront = (mFront - 1) % mCap;
}

#endif
