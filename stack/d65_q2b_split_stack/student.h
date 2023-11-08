#ifndef __STACK_STUDENT_H__
#define __STACK_STUDENT_H__
#include <algorithm>

#include "stack.h"
using namespace std;

template <typename T>
std::vector<std::vector<T>> CP::stack<T>::split_stack(int k) const {
    // your code here
    // should return something
    std::vector<CP::stack<T>> res(k);
    int box = 0;
    for (int i = mSize - 1; i >= 0; i--) {
        res[box % k].push(mData[i]);
        box++;
    }

    std::vector<std::vector<T>> ans(k);
    for (int i = 0; i < k; i++) {
        while (!res[i].empty()) {
            ans[i].push_back(res[i].top());
            res[i].pop();
        }
    }

    return ans;
}

#endif
