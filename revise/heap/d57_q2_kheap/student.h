#ifndef __STUDENT_H_
#define __STUDENT_H_

#include <iostream>

#include "priority_queue.h"

template <typename T, typename Comp>
void CP::priority_queue<T, Comp>::fixUp(size_t idx) {
    T tmp = mData[idx];
    while (idx > 0) {
        int p = (idx - 1) / 4;
        if (mLess(tmp, mData[p]))
            break;
        mData[idx] = mData[p];
        idx = p;
    }
    mData[idx] = tmp;
}

template <typename T, typename Comp>
void CP::priority_queue<T, Comp>::fixDown(size_t idx) {
    T tmp = mData[idx];
    size_t c;
    while ((c = 4 * idx + 1) < mSize) {
        int max_c = c;
        // find max child
        for (int i = 0; i < 4; i++) {
            if (c + i < mSize && mLess(mData[max_c], mData[c + i])) {
                max_c = c + i;
            }
        }
        if (mLess(mData[max_c], tmp))
            break;
        mData[idx] = mData[max_c];
        idx = max_c;
    }
    mData[idx] = tmp;
}

#endif
