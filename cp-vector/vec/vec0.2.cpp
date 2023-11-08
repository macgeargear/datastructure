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
    // * constructor
    typedef* T iterator;

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
    // * destructor
    ~vector() {
        delete[] mData;
    }

    // * copy constructor
    vector(const vector<T>& a) {
        mData = new T[a.capacity()]();
        mCap = a.capacity();
        mSize = a.size();
        for (size_t i = 0; i < a.size(); i++) {
            mData[i] = a[i];
        }
    }

    // * copy assignment operator
    vector<T>& operator=(vector<T>& other) {
        // * protect against self-destruct
        if (mData != other.mData) {
            delete[] mData;
            // copy the new data
            mData = new T[other.capacity()]();
            mCap = other.capacity();
            mSize = other.size();
            for (size_t i = 0; i < other.size(); i++) {
                mData[i] = other[i];
            }
        }
    }
    // copy assignment operator using copy-and-swap idiom
    vector<T>& operator=(vector<T> other) {  // ! notice the pass-by-value!!!
        using std::swap;
        swap(this->mSize, other.mSize);
        swap(this->mCap, other.mCap);
        swap(this->mData, other.mData);
        return *this;
    }

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

    // void push_back(const T& element) {
    //     insert(end(), element);
    // }

    void pop_back() {
        mSize--;
    }

    bool empty() const {
        return mSize == 0;
    }

    size_t size() const {
        return mSize;
    }

    size_t capacity() const {
        return mCap;
    }

    iterator begin() {
        return &mData[0];
    }
    iterator end() {
        return begin() + mSize;
    }

    iterator insert(iterator it, const& T elm) {
        size_t pos = it - begin();
        for (size_t i = mSize; i > pos; i--) {
            mData[i] = mData[i - 1];
        }
        mData[pos] = elm;
        mSize++;
        return begin() + pos;
    }

    void erase(iterator it) {
        while ((it + 1) != end()) {
            *it = *(it + 1);
            it++;
        }
        mSize--;
    }
};