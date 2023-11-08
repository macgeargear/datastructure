#ifndef __STUDENT_H_
#define __STUDENT_H_

template <typename T>
void CP::vector<T>::rotate(iterator first, iterator last, size_t k) {
    int r = last - first;
    if (r == 0 || k == 0)
        return;
    int s = first - begin();
    k %= r;
    T l[k];
    for (int i = 0; i < k; i++)
        l[i] = mData[s + i];

    for (int i = 0; i < r - k; i++)
        mData[i + s] = mData[i + s + k];
    for (int i = 0; i < k; i++)
        mData[r + s - k + i] = l[i];
}

#endif
