namespace CP {
template <typename T>
class stack {
protected:
    T* mData;
    size_t mCap;
    size_t mSize;
    void expand(size_t cap) {
    }
    void ensureCap(size_t cap) {
    }

public:
    // -- constructor
    stack(const stack<T>& a) {
    }
    stack() {
    }

    stack<T>& operator= {
    }

    ~stack() {
    }

    // -- cap
    bool empty() const {
    }

    size_t size() const {
    }

    // -- access
    const T& top() const {
    }

    // -- modifier
    void push(const T& elm) {
    }
    void pop() {
    }
}
}  // namespace CP