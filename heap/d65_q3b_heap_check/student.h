#ifndef __STUDENT_H
#define __STUDENT_H

#include <iostream>
#include <set>

#include "priority_queue.h"

template <typename T, typename Comp>
bool CP::priority_queue<T, Comp>::check() {
    // Your code here
    // Return something
    if (mSize <= 1)
        return true;
    for (int i = 1; i < mSize; i++) {
        int p = (i - 1) / 2;
        if (mLess(mData[p], mData[i]))
            return false;
    }
    return true;
}

#endif