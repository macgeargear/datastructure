#ifndef __STUDENT_H__
#define __STUDENT_H__

template <typename T>
void CP::stack<T>::moveInsert(int k, CP::stack<T> &s2, int m) {
    // your code here
    CP::stack<T> tmp_s2, tmp_s1;
    int i = 0;
    while (!s2.empty() && i < m) {
        tmp_s2.push(s2.top());
        s2.pop();
        i++;
    }

    int j = 0;
    while (!empty() && j < k) {
        tmp_s1.push(this->top());
        this->pop();
        j++;
    }

    while (!tmp_s2.empty()) {
        this->push(tmp_s2.top());
        tmp_s2.pop();
    }

    while (!tmp_s1.empty()) {
        this->push(tmp_s1.top());
        tmp_s1.pop();
    }
}
#endif
