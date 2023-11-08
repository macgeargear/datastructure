#ifndef __STUDENT_H__
#define __STUDENT_H__

#include <iostream>
using namespace std;

template <typename T>
std::vector<std::vector<T>> CP::stack<T>::distribute(size_t k) const {
    int inSize = mSize / k;
    int ex = mSize % k;

    vector<vector<T>> ans(k);
    int idx = mSize - 1;
    for (int i = 0; i < ex; i++)
        for (int j = 0; j < inSize + 1; j++)
            ans[i].push_back(mData[idx--]);

    for (int i = ex; i < k; i++)
        for (int j = 0; j < inSize; j++)
            ans[i].push_back(mData[idx--]);

    return ans;
}
#endif
