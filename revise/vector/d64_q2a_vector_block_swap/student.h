#ifndef __STUDENT_H_
#define __STUDENT_H_

#include <iostream>

#include "vector.h"
using namespace std;

template <typename T>
bool CP::vector<T>::block_swap(iterator a, iterator b, size_t m) {
    // write your code here
    int aPos = a - begin();
    int bPos = b - begin();
    if (m <= 0)
        return false;

    if (a < begin() || a >= end())
        return false;
    if (b < begin() || b >= end())
        return false;

    if (a + m - 1 >= end() || b + m - 1 >= end())
        return false;

    if (a + m - 1 >= b && b + m - 1 >= a)
        return false;

    for (int i = 0; i < m; i++) {
        std::swap(mData[aPos + i], mData[bPos + i]);
    }

    return true;
}

#endif
