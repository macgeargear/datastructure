#ifndef __STUDENT_H_
#define __STUDENT_H_

// you can include any other file here
// you are allow to use any data structure
#include <unordered_set>

#include "vector.h"

template <typename T>
void CP::vector<T>::uniq() {
    // do someting here
    std::unordered_set<T> ss;
    int cnt = 0;
    for (int i = 0; i < mSize; i++) {
        if (ss.find(mData[i]) == 0) {
            mData[cnt++] = mData[i];
            ss.insert(mData[i]);
        }
    }
    mSize = cnt;
}

#endif
