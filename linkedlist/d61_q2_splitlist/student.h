#include <iostream>

#include "list.h"

void splitList(list<T>& list1, list<T>& list2) {
    size_t pos = mSize % 2 == 0 ? (mSize / 2) : (mSize / 2 + 1);
    iterator it = begin();
    for (size_t i = 0; i < pos; i++)
        it++;

    // fix list1
    list1.mHeader->prev->next = mHeader->next;
    mHeader->next->prev = list1.mHeader->prev;
    list1.mHeader->prev->next = list1.mHeader;
    it.ptr->prev->next = list1.mHeader;

    // fix list2
    it.ptr->prev = list1.mHeader->prev;
    list2.mHeader->prev->next = it.ptr;
    list2.mHeader->prev = mHeader->prev;
    mHeader->prev->next = list2.mHeader;

    // fix *this
    mHeader->prev = mHeader;
    mHeader->next = mHeader;

    // fix Size
    mSize = 0;
    list1.mSize = pos;
    list2.mSize = mSize - pos;
}
