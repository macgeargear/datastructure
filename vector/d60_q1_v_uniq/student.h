#ifndef __STUDENT_H_
#define __STUDENT_H_

// you can include any other file here
// you are allow to use any data structure
#include <set>
#include <unordered_map>

using namespace std;

template <typename T>
void CP::vector<T>::uniq() {
    // do someting here
    set<T> s;
    for (size_t i = 0; i < mSize; i++) {
        s.insert(mData[i]);
    }
    T* tmp = new T[s.size()]();
    unordered_map<T, int> m;
    int idx = 0;
    for (size_t i = 0; i < mSize; i++) {
        if (m[mData[i]] == 0) {
            tmp[idx++] = mData[i];
            m[mData[i]]++;
        }
    }
    delete[] mData;
    this->mData = tmp;
    mSize = s.size();
    mCap = s.size();
}

#endif
