#ifndef __STUDENT_H_
#define __STUDENT_H_

#include <algorithm>

#include "list.h"

template <typename T>
void CP::list<T>::extract(const T &value, iterator a, iterator b,
                          CP::list<T> &output) {
    // write your code here
    if (empty() || a == b)
        return;
    iterator it = a;
    while (it != b) {
        if (*it == value) {
            iterator it_next(it.ptr->next);
            node *newNode =
                new node(value, output.mHeader, output.mHeader->next);

            it.ptr->next->prev = it.ptr->prev;
            it.ptr->prev->next = it.ptr->next;

            output.mHeader->next->prev = newNode;
            output.mHeader->next = newNode;
            output.mSize++;
            mSize--;
            it = it_next;
        } else {
            it++;
        }
    }
}

#endif
