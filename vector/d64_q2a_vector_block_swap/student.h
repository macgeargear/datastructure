#ifndef __STUDENT_H_
#define __STUDENT_H_
#include "vector.h"
template <typename T>
bool CP::vector<T>::block_swap(iterator a, iterator b, size_t m) {
    if (m <= 0)
        return false;
    if (!(begin() <= a && a < end()))
        return false;
    if (!(a + m - 1 < end()))
        return false;
    if (!(begin() <= b && b < end()))
        return false;
    if (!(b + m - 1 < end()))
        return false;

    // ! not collapse
    if (!(a + m - 1 < b || b + m - 1 < a))
        return false;

    for (int i = 0; i < m; i++) {
        std::swap(*(a + i), *(b + i));
    }

    return true;
}

#endif
