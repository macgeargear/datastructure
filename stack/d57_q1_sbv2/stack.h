#ifndef _CP_STACK_INCLUDED_
#define _CP_STACK_INCLUDED_

#include <iostream>
#include <stdexcept>
#include <vector>
// #pragma once

namespace CP {

template <typename T>
class stack {
protected:
    std::vector<T> v;

public:
    //-------------- constructor ----------

    // copy constructor
    stack(const stack<T>& a) {
        v = a.v;
    }

    // default constructor
    stack() {
        std::vector<T> v = {};
    }

    ~stack() {
    }

    //------------- capacity function -------------------
    bool empty() const {
        return v.empty();
    }

    //------------ to be implemented by student ----------
    size_t size() const;
    const T& top() const;
    void push(const T& element);
    void pop();
    void deep_push(const T& element, int depth);
    void multi_push(const std::vector<T>& w);
    void pop_until(const T& e);
};

}  // namespace CP

#endif
