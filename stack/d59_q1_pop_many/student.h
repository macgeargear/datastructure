#ifndef __STUDENT_H_
#define __STUDENT_H_

template <typename T>
void CP::stack<T>::multi_pop(size_t K) {
    // write your code here
    for (int i = 0; i < K; i++) {
        if (this->empty())
            break;
        this->pop();
    }
}

template <typename T>
std::stack<T> CP::stack<T>::remove_top(size_t K) {
    // write your code here
    //
    // don't forget to return an std::stack
    std::stack<T> dat, tmp;
    for (int i = 0; i < K; i++) {
        if (this->empty())
            break;
        tmp.push(this->top());
        this->pop();
    }
    while (!tmp.empty()) {
        dat.push(tmp.top());
        tmp.pop();
    }
    return dat;
}

#endif
