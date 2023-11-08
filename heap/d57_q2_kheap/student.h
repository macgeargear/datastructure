#ifndef __STUDENT_H_
#define __STUDENT_H_

#include <iostream>

#include "priority_queue.h"

template <typename T, typename Comp>
void CP::priority_queue<T, Comp>::fixUp(size_t idx) {
    T tmp = mData[idx];
    while (idx > 0) {
        size_t p = (idx - 1) / 4;
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
    size_t c, max_idx;
    while ((c = 4 * idx + 1) < mSize) {
        size_t max_idx = c;
        for (int i = 1; i < 4; i++) {
            if (c + i < mSize && mLess(mData[max_idx], mData[c + i])) {
                max_idx = c + i;
            }
        }
        if (mLess(mData[max_idx], tmp))
            break;
        mData[idx] = mData[max_idx];
        idx = max_idx;
    }
    mData[idx] = tmp;
}

#endif
