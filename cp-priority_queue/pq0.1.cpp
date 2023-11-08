#include <iostream>
using namespace std;

namespace CP {
template <typename T>
class priority_queue {
protected:
    std::vector<T> v;

public:
    bool empty() {
        return v.empty();
    }
    bool size() {
        return v.size();
    }

    void push(constT &e) {
        v.push_back(e);
    }
    T top() {
        return *std::max_element(v.begin(), v.end());
    }
    void pop() {
        v.erase(std::max_element(v.begin(), v.end()));
    }
}
}  // namespace CP