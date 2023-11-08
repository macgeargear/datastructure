#include <iostream>
using namespace std;

template <typename T>
class vector {
protected:
    T* mData;
    size_t mCap;
    size_t mSize;

    void rangeCheck(int n) {
        if (n < 0 || (size_t)n >= mSize) {
            throw std::out_of_range("index of out range");
        }
    }

    void expand(size_t capacity) {
        T* arr = new T[capacity]();
        for (size_t i = 0; i < mSize; i++) {
            arr[i] = mData[i];
        }
        delete[] mData;
        // change pointer
        mData = arr;
        mCap = capacity;
    }

    void ensureCapacity(size_t capacity) {
        if (capacity > mCap) {
            size_t s = (capacity > 2 * mCap) ? capacity : 2 * mCap;
            expand(s);
        }
    }

public:
    // TODO: constructor
    vector() {
        int cap = 1;
        mData = new T[cap]();
        mCap = cap;
        mSize = 0;
    }
    vector(size_t cap) {
        mData = new T[cap]();
        mCap = cap;
        mSize = cap;
    }
    // TODO: destructor
    ~vector() {
        delete[] mData;
    }

    // TODO: copy constructor

    T& at(int index) {
        rangeCheck(index);
        return mData[index];
    }

    T& operator[](int index) {
        rangeCheck(index);
        return mData[index];
    }

    void push_back(const T& element) {
        ensureCapacity(mSize + 1);
        mData[mSize] = element;
        mSize++;
    }
    void pop_back() {
        mSize--;
    }
};