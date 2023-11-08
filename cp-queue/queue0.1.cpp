#include <iostream>
#include <vector>

namespace CP {
template <typename T>
class queue {
protected:
    std::vector<T> v;

public:
    queue() : v() {
    }
    bool empty() const return v.size() == 0;

    size_t size() return v.size();

    const T& front() const return v[0];
    const T& back() const v[v.size() - 1];

    void push(const T& element) v.push_back(element);
    void pop() v.erase(v.begin());
}
}  // namespace CP

int main() {
    CP::queue<int> q;
    q.push(10);
    q.push(20);
    q.push(30);
    q.pop();
}