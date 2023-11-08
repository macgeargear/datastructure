#ifndef __STUDENT_H_
#define __STUDENT_H_

#include <iostream>
#include <vector>

#include "queue.h"

template <typename T>
std::vector<T> CP::queue<T>::to_vector(int k) const {
    int n = std::min(k, (int)mSize);
    std::vector<T> res(n);
    // write your code only here
    //
    for (int i = 0; i < n; i++) {
        res[i] = this->mData[(mFront + i) % mCap];
    }

    return res;
}

template <typename T>
CP::queue<T>::queue(iterator from, iterator to) {
    // write your code only here
    int n = to - from;
    T* mData = new T[n]();
    int i = 0;
    for (auto it = from; it != to; it++) {
        mData[i++] = *it;
    }

    this->mData = mData;
    this->mSize = n;
    this->mCap = mSize;
    this->mFront = 0;
}

#endif
