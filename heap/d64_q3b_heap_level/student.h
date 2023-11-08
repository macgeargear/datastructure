#ifndef __STUDENT_H__
#define __STUDENT_H__

#include <algorithm>
#include <cmath>
#include <vector>

#include "priority_queue.h"

template <typename T, typename Comp>
std::vector<T> CP::priority_queue<T, Comp>::at_level(size_t k) const {
    // write your code here
    // can include anything
    std::vector<T> r;
    for (int i = 0; i < mSize; i++) {
        if (i >= pow(2, k) - 1 && i <= pow(2, k + 1) - 2 && k < log2(mSize))
            r.push_back(mData[i]);
    }
    sort(r.rbegin(), r.rend(), mLess);
    return r;
}

#endif
