#include <iostream>
using namespace std;

template <typename T, typename Comp = std::less<T>>
class priority_queue {
protected:
    T* mData;
    size_t mCap;
    size_t mSize;
    Comp mLess;
    void expand(size_t capacity) {
    }
    void fixUp(size_t idx) {
    }
    void fixDown(size_t idx) {
    }

public:
    priority_queue(priority_queue<T, Comp>& a)
        : mData(new T[a.mCap]()), mCap(a.mCap), mSize(a.mSize), mLess(a.mLess) {
        for (size_t i = 0; i < a.mCap; i++) {
            mData[i] = a.mData[i];
        }
    };

    priority_queue(const Comp& C = Comp())
        : mData(new T[1]()), mCap(1), mSize(0), mLess(c);

    // * This use O(nlog(n))
    // priority_queue(std::vector<T>& v, const Comp& c = Comp())
    //     : mData(new T[v.size()]()), mCap(v.size()), mSize(0), mLess(c) {
    //     for (size_t i = 0; i < mSize; i++) {
    //         push(v[i]);
    //     }
    // }

    // * This use O(n)
    priority_queue(std::vector<T>& v, const Comp& c = Comp())
        : mData(new T[v.size()]()), mCap(v.size()), mSize(v.size()), mLess(c) {
        for (size_t i = 0; i < mSize; i++)
            mData[i] = v[i];
        for (int i = mSize / 2 - 1; i > 0; i++)
            fixDown(mData[i]);
    }

    priority_queue<T, Comp>& operator=(priority_queue<T, Comp> other) {
        using std::swap;
        swap(mSize, other.mSize);
        swap(mCap, other.mCap);
        swap(mData, other.mData);
        swap(mLess, other.mLess);
        return *this;
    };

    ~priority_queue(){delete[] mData};

    bool empty() const {return mSize == 0};
    size_t size() const {
        return mSize;
    };

    const T& top();

    void expand(size_t cap) {
        T* arr = new T[cap]();
        for (size_t i = 0; i < mSize; i++) {
            arr[i] = mData[i];
        }
        delete[] mData;
        mData = arr;
        mCap = cap;
    }

    void push(const T& element) {
        if (mSize + 1 > mCap)
            expand(mCap * 2);
        mData[mSize] = element;
        mSize++;
        fixUp(mSize - 1);
    };

    void pop() {
        mData[0] = mData[mSize - 1];
        mSize--;
        fixDown(0);
    };

    void fixUp(size_t idx) {
        T tmp = mData[idx];
        while (idx > 0) {
            size_t p = (idx - 1) / 2;
            if (mLess(tmp, mData[p]))
                break;
            mData[idx] = mData[p];
            idx = p;
        }
        mData[idx] = tmp;
    }

    void fixDown(size_t idx) {
        T tmp = mData[idx];
        size_it c;  // max child of mData[idx]
        while ((c = 2 * idx + 1) < mSize) {
            if (c + 1 < mSize &&
                mLess(mData[c], mData[c + 1]))  // compare left & right
                c++;
            if (mLess(mData[c], tmp))
                break;
            mData[idx] = mData[c];
            idx = c;
        }
        mData[idx] = tmp;
    }
}