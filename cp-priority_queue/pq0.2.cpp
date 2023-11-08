#include <algorithm>
#include <iostream>
#include <vector>
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

    // * a bit slow
    void push(constT &e) {
        // * sol 1
        // v.push_back(e);
        // sort(v.begin(), v.end());

        // * sol 2
        // O(n)
        auto it = v.begin();
        while (it < v.end() && *it <= e) {
            it++;
        }
        v.insert(it, e);  // O(n)

        // * sol 3
        // O(n)
        v.insert(upper_bound(v.begin(), v.end(), e), e);
    }

    T top() {
        return v.back();
    }
    void pop() {
        v.pop_back();
    }
}
}  // namespace CP