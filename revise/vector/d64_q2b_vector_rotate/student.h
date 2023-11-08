#ifndef __STUDENT_H_
#define __STUDENT_H_

#include <algorithm>
#include <iostream>

#include "vector.h"

template <typename T>
void CP::vector<T>::rotate(iterator first, iterator last, size_t k) {
    if (k == 0)
        return;

    std::rotate(first, first + k % (last - first), last);
}

#endif
