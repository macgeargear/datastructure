#ifndef __STACK_STUDENT_H__
#define __STACK_STUDENT_H__
#include "stack.h"

// DO NOT INCLUDE ANYTHING
#include <iostream>

template <typename T>
CP::stack<T>::stack(typename std::set<T>::iterator first,
                    typename std::set<T>::iterator last) {
    int n = 0;
    for (auto it = first; it != last; it++)
        n++;
    T* tmp = new T[n]();
    int i = 0;
    for (auto it = first; it != last; it++) {
        tmp[n - i - 1] = *it;
        i++;
    }

    this->mData = tmp;
    mSize = n;
    mCap = n;
}

#endif
