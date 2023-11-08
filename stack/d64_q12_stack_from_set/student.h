#ifndef __STACK_STUDENT_H__
#define __STACK_STUDENT_H__
#include "stack.h"

// DO NOT INCLUDE ANYTHING
#include <iostream>

template <typename T>
CP::stack<T>::stack(typename std::set<T>::iterator first,
                    typename std::set<T>::iterator last) {
    // write your code ONLY here
    CP::stack<T> tmp;
    int n = 0;
    for (auto it = first; it != last; it++) {
        tmp.push(*it);
        n++;
    }

    T* mData = new T[n];
    int i = 0;
    while (!tmp.empty()) {
        mData[i++] = tmp.top();
        tmp.pop();
    }

    this->mData = mData;
    mSize = n;
    mCap = n;
}

#endif
