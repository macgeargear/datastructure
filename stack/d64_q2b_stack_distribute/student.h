#ifndef __STUDENT_H__
#define __STUDENT_H__

#include <iostream>

#include "stack.h"

template <typename T>
std::vector<std::vector<T>> CP::stack<T>::distribute(size_t k) const {
    std::vector<std::vector<T>> res(k);
    int elmSize = mSize / k;
    int rest = mSize % k;
    int idx = mSize - 1;
    for (size_t i = 0; i < rest; i++) {
        std::vector<T> elm(elmSize + 1);
        for (int j = 0; j < elmSize + 1; j++) {
            elm[j] = mData[idx--];
        }
        res[i] = elm;
    }

    // * for the rest data in stack
    for (int i = rest; i < k; i++) {
        std::vector<T> elm(elmSize);
        for (int j = 0; j < elmSize; j++) {
            elm[j] = mData[idx--];
        }
        res[i] = elm;
    }

    return res;
}
#endif

/*
10 4
1 2 3 4 5 6 7 8 9 10
--
8 3
1 2 3 4 5 6 7 8
*/