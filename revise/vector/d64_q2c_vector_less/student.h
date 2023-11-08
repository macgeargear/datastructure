#ifndef __STUDENT_H_
#define __STUDENT_H_

#include "vector.h"

template <typename T>
bool CP::vector<T>::operator<(const CP::vector<T> &other) const {
    // write your code here
    //  if you use std::vector, your score will be half (grader will report
    //  score BEFORE halving)

    if (size() == 0 && other.size() != 0)
        return true;

    int i = 1;
    if (size() != 0 && other.size() != 0) {
        if (mData[0] < other[0])
            return true;
        for (; i < std::min(mSize, other.size()); i++) {
            if (mData[i] <= other[i])
                continue;
            else
                return false;
        }
    }
    if (i == mSize && other.size() == mSize) {
        return mData[mSize - 1] < other[other.size() - 1];
    }
    return i == mSize && mSize != other.size();
}

#endif
