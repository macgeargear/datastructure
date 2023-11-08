#ifndef __STUDENT_H__
#define __STUDENT_H__

#include <algorithm>
#include <cmath>
#include <vector>

#include "priority_queue.h"

template <typename T, typename Comp>
T CP::priority_queue<T, Comp>::get_kth(size_t k) const {
    // write your code here
    // can include anything
    if (k == 1)
        return mData[0];
    if (k == 2)
        if (mLess(mData[1], mData[2]))
            return mData[2];
        else
            return mData[1];
    size_t s = std::min(mSize, size_t(pow(2, k) - 1));
    std::vector<T> v(s);
    for (int i = 0; i < s; i++) {
        v[i] = mData[i];
    }
    sort(v.begin(), v.end(), mLess);
    return v[v.size() - k];
}

#endif
