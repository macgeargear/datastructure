#ifndef __STUDENT_H_
#define __STUDENT_H_

#include "vector.h"

template <typename T>
void CP::vector<T>::insert(iterator position, iterator first, iterator last) {
    // write your code here
    int pos = position - begin();
    ensureCapacity(size() + last - first);

    for (int i = mSize - 1; i >= pos; i--) {
        mData[i + (last - first)] = mData[i];
    }

    for (int i = 0; i < last - first; i++) {
        mData[pos + i] = *(first + i);
    }

    mSize += last - first;
}

#endif
