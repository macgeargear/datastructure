#ifndef __STUDENT_H_
#define __STUDENT_H_

#include <algorithm>
#include <vector>

template <typename T>
template <typename Comp>
T CP::queue<T>::min_element(std::vector<size_t> pos, Comp comp) const {
    // your code here
    std::vector<T> v;
    for (auto p : pos)
        if (p < mSize) {
            v.push_back(mData[(mFront + p) % mCap])
        }

    // should return something
    return std::min_element(v.begin(), v.end(), comp);
}

#endif
