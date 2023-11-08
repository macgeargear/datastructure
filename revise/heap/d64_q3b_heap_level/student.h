#ifndef __STUDENT_H__
#define __STUDENT_H__

#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

#include "priority_queue.h"

template <typename T, typename Comp>
std::vector<T> CP::priority_queue<T, Comp>::at_level(size_t k) const {
    // write your code here
    // can include anything
    int start, stop;
    start = pow(2, k) - 1;
    stop = pow(2, k + 1) - 2;
    std::vector<T> r;
    if (pow(2, k) - 1 > mSize)
        return r;
    for (int i = start; i <= std::min((int)mSize - 1, stop); i++) {
        r.push_back(mData[i]);
    }
    sort(r.rbegin(), r.rend(), mLess);
    return r;
}

#endif
