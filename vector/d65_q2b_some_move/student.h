#ifndef __STUDENT_H_
#define __STUDENT_H_

#include <algorithm>
#include <iostream>
#include <vector>

#include "vector-sm.h"

template <typename T>
void CP::vector_some_move<T>::insert(int index, std::vector<T>& value) {
    // Your code here
    int i = upper_bound(aux.begin(), aux.end(), index) - aux.begin();
    int treshold = 2000;
    if (i > 0)
        index -= aux[i - 1];

    if (i == mData.size()) {
        mData.push_back(value);
    } else {
        mData[i].insert(mData[i].begin() + index, value.begin(), value.end());
        if (mData[i].size() > treshold) {
            mData.insert(
                mData.begin() + i + 1,
                std::vector<T>(mData[i].begin() + treshold, mData[i].end()));
            mData[i].resize(treshold);
        }
    }

    aux.resize(mData.size());
    for (; i < mData.size(); i++) {
        if (i == 0)
            aux[i] = mData[i].size();
        else
            aux[i] = aux[i - 1] + mData[i].size();
    }

    mSize = mCap = aux.back();
}

#endif