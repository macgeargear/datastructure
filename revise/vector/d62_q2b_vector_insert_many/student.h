#ifndef __STUDENT_H_
#define __STUDENT_H_

#include <algorithm>
#include <iostream>

#include "vector.h"

template <typename T>
void CP::vector<T>::insert_many(CP::vector<std::pair<int, T>> data) {
    int n = mSize + data.size();
    sort(data.begin(), data.end());
    int ind = 0, j = 0;
    T* tmp = new T[n]();
    for (int i = 0; i <= mSize; i++) {
        if (data[ind].first == i)
            tmp[j++] = data[ind++].second;
        tmp[j++] = mData[i];
    }

    delete[] mData;
    mData = tmp;
    mSize = n;
    mCap = mSize;
}

#endif
