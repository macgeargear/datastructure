#ifndef __STUDENT_H_
#define __STUDENT_H_

template <typename T>
void CP::stack<T>::deep_push(size_t pos, const T& value) {
    // write your code here
    if (pos == 0) {
        this->push(value);
        return;
    }

    CP::stack<int> tmp;
    for (int i = 0; i < pos; i++) {
        tmp.push(this->top());
        this->pop();
    }
    this->push(value);
    while (!tmp.empty()) {
        this->push(tmp.top());
        tmp.pop();
    }
}

#endif
