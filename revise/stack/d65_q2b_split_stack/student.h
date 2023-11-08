#ifndef __STACK_STUDENT_H__
#define __STACK_STUDENT_H__
#include <algorithm>

#include "stack.h"

template <typename T>
std::vector<std::vector<T>> CP::stack<T>::split_stack(int k) const {
    std::vector<std::vector<T>> ans(k);
    for (int i = 0; i < mSize; i++) {
        ans[i % k].insert(ans[i % k].begin(), mData[mSize - i - 1]);
    }
    return ans;
}

#endif
