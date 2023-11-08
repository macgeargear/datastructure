#ifndef __STUDENT_H_
#define __STUDENT_H_

#include "vector.h"

template <typename T>
void CP::vector<T>::erase_many(const std::vector<int> &pos) {
    // write your code here
    int idx = pos.size() - 1;
    for (int i = this->mSize - 1; i >= 0; i--) {
        if (i == idx) {
            this->erase(&mData[0] + pos[idx]);
            idx--;
        }
    }
}

#endif
