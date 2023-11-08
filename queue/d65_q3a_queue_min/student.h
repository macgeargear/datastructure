#ifndef __STUDENT_H_
#define __STUDENT_H_

#include <algorithm>
#include <iostream>
#include <vector>

#include "queue.h"

template <typename T>
template <typename Comp>
T CP::queue<T>::min_element(std::vector<size_t> pos, Comp comp) const {
    // your code here
    T min;
    bool first = true;
    for (auto &x : pos) {
        if (x >= mSize)
            continue;
        int ind = (mFront + x) % mCap;
        if (first) {
            min = mData[ind];
            first = false;
            continue;
        }
        if (comp(mData[ind], min)) {
            min = mData[ind];
        }
    }

    // should return something
    return min;
}

#endif
