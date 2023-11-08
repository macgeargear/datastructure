#ifndef __STUDENT_H_
#define __STUDENT_H_

// You can include library here
#include <algorithm>
#include <iostream>
#include <vector>

#include "vector.h"

template <typename T>
void CP::vector<T>::range_erase(
    std::vector<std::pair<iterator, iterator>> &ranges) {
    std::vector<std::pair<int, int>> r;
    for (auto &[a, b] : ranges)
        r.push_back({a - begin(), b - begin()});
    sort(r.begin(), r.end());
    int k = 0, j = 0;
    for (int i = 0; i < mSize; i++) {
        while (k < r.size() && r[k].second <= i)
            k++;

        if (k < r.size() && i >= r[k].first)
            continue;
        mData[j++] = mData[i];
    }

    mSize = j;
}

#endif
