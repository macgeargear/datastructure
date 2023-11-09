#ifndef __STUDENT_H_
#define __STUDENT_H_

template <typename T>
void CP::list<T>::remove_all(const T& value) {
    // write your code here
    iterator it = begin();
    iterator prev = mHeader;
    while (it != end()) {
        bool hasDup = false;
        iterator curr = it;
        while (*curr == value) {
            iterator curr_next = curr.ptr->next;
            hasDup = true;
            delete curr.ptr;
            mSize--;
            curr = curr_next;
        }
        if (hasDup) {
            curr.ptr->prev = prev.ptr;
            prev.ptr->next = curr.ptr;
            prev.ptr = it.ptr;
            it = curr;
        } else {
            prev.ptr = it.ptr;
            it++;
        }
    }
}

#endif
