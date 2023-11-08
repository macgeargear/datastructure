#ifndef __STUDENT_H_
#define __STUDENT_H_

#include <stdio.h>

#include <cmath>
#include <iostream>

#include "priority_queue.h"

template <typename T, typename Comp>
bool CP::priority_queue<T, Comp>::find(T k) const {
    // your code here
    for (int i = 0; i < mSize; i++)
        if (mData[i] == k)
            return true;
    return false;
}

template <typename T, typename Comp>
int CP::priority_queue<T, Comp>::find_level(T k) const {
    // your code here
    // int h = 0;
    // bool found = false;
    // for (int i = 0; i < mSize; i++) {
    //     if (mData[i] == k) {
    //         found = true;
    //         if ((int)(log2(i + 1)) > h)
    //             h = (int)(log2(i + 1));
    //     }
    // }
    // if (found)
    //     return h;
    // return -1;
    if (k > mData[0])
        return -1;
    for (int i = mSize - 1; i >= 0; i--)
        if (mData[i] == k)
            return (int)log2(i + 1);
    return -1;
}

/*
       7(0)
     /      \
    4(1)     6(2)
   /   \    /   \
  1(3) 3(4) 2(5) 5(6)
*/

#endif
