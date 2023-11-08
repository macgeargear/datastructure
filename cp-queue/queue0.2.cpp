#include <iostream>
#include <vector>

namespace CP {
template <typename T>
class queue {
protected:
    std::vector<T> v;
    int mFront;  // head of queue

public:
    queue() : v(), mFront() {
    }
    bool empty() const {
        return v.size() == 0;
    }

    size_t size() {
        return v.size() - mFront;
    }

    const T& front() const {
        return v[mFront];
    }
    const T& back() const {
        return v[v.size() - 1];
    }

    void push(const T& element) {
        v.push_back(element);
    }
    void pop() {
        mFront++;
    }
};
}  // namespace CP

int main() {
    CP::queue<int> q;
    q.push(10);
    q.push(20);
    q.push(30);
    q.pop();
}