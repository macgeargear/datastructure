#ifndef __STUDENT_H_
#define __STUDENT_H_

#include <vector>

#include "queue.h"

template <typename T>
std::vector<T> CP::queue<T>::to_vector(int k) const {
    std::vector<T> res;
    // write your code only here
    int n = std::min(k, (int)mSize);
    for (int i = 0; i < n; i++) {
        res.push_back(mData[(mFront + i) % mCap]);
    }
    //
    return res;
}

template <typename T>
CP::queue<T>::queue(iterator from, iterator to) {
    // write your code only here
    int n = to - from;
    T* mData = new T[n]();
    for (int i = 0; i < n; i++) {
        mData[i] = *(from + i);
    }
    this->mData = mData;
    mSize = n;
    mCap = n;
    mFront = 0;
}

#endif
