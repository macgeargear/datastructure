#ifndef __STUDENT_H_
#define __STUDENT_H_

#include <iostream>

#include "vector.h"
template <typename T>
bool CP::vector<T>::operator<(const CP::vector<T> &other) const {
    if (size() == 0 && other.size() != 0)
        return true;

    if ((size() == 0 && other.size() == 0) ||
        (size() != 0 && other.size() == 0)) {
        return false;
    }

    int n = std::min(size(), other.size());
    for (int i = 0; i < n; i++) {
        if (mData[i] < other[i])
            return true;
        if (mData[i] > other[i])
            return false;
        if (i == n - 1 && other.size() > n)
            return true;
    }

    return false;
}

#endif
