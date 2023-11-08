#ifndef __STUDENT_H_
#define __STUDENT_H_

template <typename T>
CP::list<T> CP::list<T>::split(iterator it, size_t pos) {
    // write your code here
    CP::list<T> result;
    auto tmp = mHeader->prev;
    int n = mSize - pos;
    if (n < 0) {
        mSize = 0;
        result.mSize = pos;
    } else {
        mSize = pos;
        result.mSize = n;
    }

    // * fix mHeader
    it.ptr->prev->next = mHeader;
    mHeader->prev = it.ptr->prev;

    // * fix result
    result.mHeader->next = it.ptr;
    result.mHeader->prev = tmp;
    it.ptr->prev = result.mHeader;
    tmp->next = result.mHeader;

    return result;
}

#endif
