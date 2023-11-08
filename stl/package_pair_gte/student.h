#ifndef __STUDENT_H_
#define __STUDENT_H_
#include "pair.h"

template <typename T1, typename T2>
bool CP::pair<T1, T2>::operator>=(const pair<T1, T2>& other) const {
    // write your code here
    if (first != other.first) {
        return first >= other.first;
    }
    return second >= other.second;
}

#endif
