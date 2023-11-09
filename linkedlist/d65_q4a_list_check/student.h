#ifndef __STUDENT_H__
#define __STUDENT_H__

#include "list.h"

template <typename T>
bool CP::list<T>::check() {
    // your code here
    if (mSize == 0)
        return mHeader->next == mHeader && mHeader->prev == mHeader;
    iterator it = begin(), prev = mHeader;
    while (it != end()) {
        if (!(it.ptr->prev == prev.ptr && prev.ptr->next == it.ptr))
            return false;
        prev = it;
        it++;
    }

    return true;
}

#endif
