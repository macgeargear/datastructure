#ifndef __STACK_STUDENT_H__
#define __STACK_STUDENT_H__
#include <iostream>
#include <vector>

#include "stack.h"

template <typename T>
void CP::stack<T>::mitosis(int a, int b) {
    CP::stack<T> dup, tmp;
    int i = 0;
    while (!empty() && i <= b) {
        T curr = this->top();
        if (i < a) {
            tmp.push(curr);
        } else {
            dup.push(curr);
        }
        this->pop();
        i++;
    }

    while (!dup.empty()) {
        T curr = dup.top();
        this->push(curr);
        this->push(curr);
        dup.pop();
    }

    while (!tmp.empty()) {
        T curr = tmp.top();
        this->push(curr);
        tmp.pop();
    }
}

#endif

/*
* 1 2
i=2
tmp: 5
dup: 4 3
*/