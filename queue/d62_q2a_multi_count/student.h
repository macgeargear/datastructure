#ifndef __STUDENT_H_
#define __STUDENT_H_

#include <algorithm>
#include <map>
#include <vector>

template <typename T>
std::vector<std::pair<T, size_t>> CP::queue<T>::count_multi(
    std::vector<T> &k) const {
    // write your code here
    std::map<T, int> m;
    std::vector<std::pair<T, size_t>> res;
    for (int i = 0; i < size(); i++) {
        m[mData[(mFront + i) % mCap]]++;
    }

    for (auto &x : k) {
        if (m.find(x) == m.end())
            res.push_back({x, 0});
        else
            res.push_back({x, m[x]});
    }
    return res;
}

#endif
