#ifndef __STUDENT_H_
#define __STUDENT_H_

using namespace std;

#include <algorithm>
#include <vector>

template <typename T, typename Comp>
size_t CP::priority_queue<T, Comp>::get_rank(size_t pos) const {
    size_t p = 0;
    for (int i = 0; i < mSize; i++) {
        if (mLess(mData[pos], mData[i]))
            p++;
    }
    return p;
}

/*
0 1 2 3 4
5 4 3 2 1
0 -> 0
1 -> 1
2 -> 2
3 ->
*/

#endif
