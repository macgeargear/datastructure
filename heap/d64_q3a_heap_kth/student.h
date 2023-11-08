#ifndef __STUDENT_H__
#define __STUDENT_H__

#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

#include "priority_queue.h"

template <typename T, typename Comp>
T CP::priority_queue<T, Comp>::get_kth(size_t k) const {
    if (k == 1)
        return mData[0];
    if (k == 2) {
        if (!mLess(mData[1], mData[2]))
            return mData[1];
        else
            return mData[2];
    }
    if (k == 3) {
        if (!mLess(mData[1], mData[2])) {
            if (!mLess(mData[3], mData[2]) || !mLess(mData[4], mData[2]))
                return !mLess(mData[3], mData[4]) ? mData[3] : mData[4];
            return mData[2];
        } else {
            if (!mLess(mData[5], mData[1]) || !mLess(mData[6], mData[1]))
                return !mLess(mData[5], mData[6]) ? mData[5] : mData[6];
            return mData[1];
        }
    }
}

#endif
