#ifndef __STUDENT_H_
#define __STUDENT_H_

#include <algorithm>

#include "vector-nm.h"

template <typename T>
T& CP::vector_no_move<T>::operator[](int idx) {
    // your code here
    int index = upper_bound(aux.begin(), aux.end(), idx) - aux.begin();

    // .      0 1 2 3    0 1 . 0 1 2 3 4 5 6 7 8
    // mData: 0 1 2 3 |  4 5 | 6 7 8 9 10 11 12 13
    //           0        1             2
    // size:     4 .      2 .           8
    // ---
    // * aux: 4 | 6 | 14
    // 0 -> [0][0]
    // 3 -> [0][3]
    // * 4 -> [1][0]
    // 5 -> [1][1]
    // * 6 -> [2][0]
    // * 9 -> [2][3]
    //              2    6 - 6 = 0
    return mData[index][idx - aux[index - 1]];
}

template <typename T>
void CP::vector_no_move<T>::expand_hook() {
    // your code here
    // you MAY need this function
    this->aux.push_back(mCap);
}

#endif
