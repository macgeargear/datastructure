#ifndef __STUDENT_H_
#define __STUDENT_H_

#include <math.h>

template <typename T>
int CP::stack<T>::compare_reserve(const CP::stack<T> &other) const {
    // write your code here
    int my_reserve = pow(2, log2(mSize) + 1) - mSize;
    int other_reserve = pow(2, log2(other.size()) + 1) - other.size();
    if (my_reserve < other_reserve)
        return -1;
    else if (my_reserve == other_reserve)
        return 0;
    else
        return 1;
}

#endif
