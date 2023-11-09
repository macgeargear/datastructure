#include "list.h"

void shift(int k) {
    // TODO: Add your code here
    while (k < 0)
        k += mSize;
    k %= mSize;
    while (k--) {
        iterator shifted = mHeader->next;
        mHeader->next = mHeader->next->next;
        shifted.ptr->prev = mHeader->prev;
        shifted.ptr->next = mHeader;
        mHeader->next->prev = mHeader;
        mHeader->prev->next = shifted.ptr;
        mHeader->prev = shifted.ptr;
    }
}
