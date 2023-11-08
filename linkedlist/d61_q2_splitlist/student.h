#include <iostream>

void splitList(list<T>& list1, list<T>& list2) {
    // Add your code here
    int m = mSize % 2 == 0 ? mSize / 2 : mSize / 2 + 1;
    auto it = begin();
    for (int i = 1; i < m; i++)
        it++;

    auto tmp = it.ptr->next;

    it.ptr->next = list1.mHeader;
    list1.mHeader->prev->next = mHeader->next;
    mHeader->next->prev = list1.mHeader->prev;
    list1.mHeader->prev = it.ptr;
    list1.mSize += m;

    list2.mHeader->prev->next = tmp;
    list2.mHeader->prev = mHeader->prev;
    tmp->prev = list2.mHeader;
    mHeader->prev->next = list2.mHeader;
    list2.mSize += mSize - m;

    clear();
    // mHeader->next = NULL;
    // mHeader->prev = NULL;
    std::cout << list1.size() << " " << list2.size() << " " << size() << "\n";
    mSize = 0;
}
