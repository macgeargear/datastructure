#ifndef __STUDENT_H_
#define __STUDENT_H_

#include <algorithm>
#include <iostream>
#include <vector>

#include "vector.h"
#define all(x) (x).begin(), (x).end()

template <typename T>
void CP::vector<T>::insert_many(CP::vector<std::pair<int, T>> data) {
    // write your code here
    sort(data.begin(), data.end());

    T* tmp = new T[data.size() + mSize]();
    int idx = 0, k = 0;

    for (size_t i = 0; i <= this->size(); i++) {
        if (i == data[idx].first) {
            tmp[k++] = data[idx++].second;
        }
        tmp[k++] = mData[i];
    }

    int newSize = data.size() + mSize;
    delete[] mData;
    this->mData = tmp;
    this->mSize = newSize;
    this->mCap = newSize;
}

#endif
/*
6
1 2 3 4 5 6
3
0 10
6 11
2 12
*/
