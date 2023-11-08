#ifndef __STUDENT_H_
#define __STUDENT_H_

#include <algorithm>
#include <map>

template <typename T>
std::vector<std::pair<T, size_t>> CP::queue<T>::count_multi(
    std::vector<T> &k) const {
    // write your code here
    std::vector<std::pair<T, size_t>> v;
    std::map<T, size_t> m;

    for (auto &x : k)
        m[x] = 0;
    for (int i = 0; i < mSize; i++) {
        if (m.find(mData[i]) != m.end()) {
            m[mData[i]]++;
        }
    }

    for (auto &x : k) {
        v.push_back({x, m[x]});
    }
    return v;
}

#endif
