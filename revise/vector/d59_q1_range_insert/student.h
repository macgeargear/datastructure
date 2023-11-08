#ifndef __STUDENT_H_
#define __STUDENT_H_

#include "vector.h"

template <typename T>
void CP::vector<T>::insert(iterator position, iterator first, iterator last) {
    // write your code here
    int n = last - first;
    int pos = position - begin();
    ensureCapacity(mCap + n);
    for (int i = mSize - 1; i >= pos; i--) {
        mData[i + n] = mData[i];
    }
    for (int i = 0; i < n; i++) {
        mData[pos + i] = *(first + i);
        d60_q1_v_uniq
    }
    mSize += n;
}

#endif
