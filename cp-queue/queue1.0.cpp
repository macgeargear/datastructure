#include <iostream>
#include <vector>

namespace CP {
template <typename T>
class queue {
protected:
    T* mData;
    size_t mCap;
    size_t mSize;
    size_t mFront;

    void expand(size_t cap) {
        T* arr = new T[cap]();
        for (size_t i = 0; i < mSize; i++) {
            arr[i] = mData[(mFront + i) % mCap];
        }
        delete[] mData;
        mData = arr;
        mCap = cap;
        mFront = 0;
    }

    void ensureCapacity(size_t cap) {
        if (cap > mCap) {
            size_t s = (cap > 2 * mCap) ? cap : 2 * mCap;
            expand(s);
        }
    }

public:
    // * Default
    queue() : mData(new T[1]()), mCap(1), mSize(0), mFront(0) {
    }

    // * Copy
    queue(const queue<T>& a)
        : mData(new T[a.mCap]()),
          mCap(a.mCap),
          mSize(a.mSize),
          mFront(a.mFront) {
        for (size_t i = 0; i < a.mCap; i++) {
            mData[i] = a.mData[i];
        }
    }

    queue<T> operator=(queue<T> other) {
        using std::swap;
        swap(mSize, other.mSize);
        swap(mCap, other.mCap);
        swap(mData, other.mData);
        swap(mFront, other.mFront);
        return *this;
    }

    ~queue() {
    }

    bool empty() const {
        return size() == 0;
    }

    size_t size() {
        return mSize;
    }

    const T& front() const {
        return mData[mFront];
    }

    const T& back() const {
        return mData[(mFront + mSize - 1) % mCap];
    }

    void push(const T& element) {
        ensureCapacity(mSize + 1);
        mData[(mFront + mSize) % mCap] = element;
        mSize++;
    }

    void pop() {
        mFront = (mFront + 1) % mCap;
        mSize--;
    }

    void push_front() {
    }

    void pop_back() {
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