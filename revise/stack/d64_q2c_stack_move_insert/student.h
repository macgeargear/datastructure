#ifndef __STUDENT_H__
#define __STUDENT_H__

template <typename T>
void CP::stack<T>::moveInsert(int k, CP::stack<T> &s2, int m) {
    // your code here
    CP::stack<T> thisTmp, sTmp;
    while (!s2.empty() && m--) {
        sTmp.push(s2.top());
        s2.pop();
    }
    while (!empty() && k--) {
        thisTmp.push(top());
        pop();
    }

    while (!sTmp.empty()) {
        push(sTmp.top());
        sTmp.pop();
    }

    while (!thisTmp.empty()) {
        push(thisTmp.top());
        thisTmp.pop();
    }
}
#endif
