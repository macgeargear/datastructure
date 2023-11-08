#ifndef __STUDENT_H_
#define __STUDENT_H_

#include <stdio.h>

#include <iostream>

#include "priority_queue.h"

template <typename T, typename Comp>
int CP::priority_queue<T, Comp>::height() const {
    // write your code here
    if (mSize == 0)
        return -1;
    int h = 0;
    int idx = mSize - 1;
    while (idx > 0) {
        idx = (idx - 1) / 2;
        h++;
    }
    return h;
}

#endif
