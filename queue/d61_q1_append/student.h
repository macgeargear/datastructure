#include "queue.h"
#include "stack.h"

namespace CP {
template <typename T>
void stack<T>::appendStack(stack<T> s) {
    stack<T> tmp;
    while (!empty()) {
        tmp.push(top());
        pop();
    }

    stack<T> tmp2;
    while (!s.empty()) {
        tmp2.push(s.top());
        s.pop();
    }

    while (!tmp2.empty()) {
        push(tmp2.top());
        tmp2.pop();
    }

    while (!tmp.empty()) {
        push(tmp.top());
        tmp.pop();
    }
}

template <typename T>
void stack<T>::appendQueue(queue<T> q) {
    stack<T> tmp, tmp2;
    while (!empty()) {
        tmp.push(top());
        pop();
    }

    while (!q.empty()) {
        tmp2.push(q.front());
        q.pop();
    }

    while (!tmp2.empty()) {
        push(tmp2.top());
        tmp2.pop();
    }

    while (!tmp.empty()) {
        push(tmp.top());
        tmp.pop();
    }
}

template <typename T>
void queue<T>::appendStack(stack<T> s) {
    queue<T> tmp;
    while (!s.empty()) {
        tmp.push(s.top());
        s.pop();
    }

    while (!tmp.empty()) {
        push(tmp.front());
        tmp.pop();
    }
}

template <typename T>
void queue<T>::appendQueue(queue<T> q) {
    while (!q.empty()) {
        push(q.front());
        q.pop();
    }
}
}  // namespace CP
