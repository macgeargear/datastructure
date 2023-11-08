#ifndef __STUDENT_H_
#define __STUDENT_H_

#include <algorithm>

template <typename T>
typename CP::list<T>::iterator CP::list<T>::reverse(iterator a, iterator b) {
    // write your code here
    auto it1 = a, it2 = b;
    if (a == b)
        return a;
    it2--;
    while (it1 != it2) {
        std::swap(*it1, *i2);
        it1++;
        if (it1 == it2)
            break;
        it2--;
    }
    return a;
}

#endif
