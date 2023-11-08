#ifndef _STUDENT_H_INCLUDED
#define _STUDENT_H_INCLUDED
#include <iostream>

#include "queue.h"

template <typename T>
void CP::queue<T>::reverse() {
    // Your code here
    aux = !aux;
}

template <typename T>
const T& CP::queue<T>::front() const {
    // You MAY need to edit this function
    if (aux == 0) {
        return mData[mFront];
    }
    return mData[(mFront + mSize - 1) % mCap];
}

template <typename T>
const T& CP::queue<T>::back() const {
    // You MAY need to edit this function
    if (aux == 0) {  // default
        return mData[(mFront + mSize - 1) % mCap];
    }
    return mData[mFront];
}

template <typename T>
void CP::queue<T>::push(const T& element) {
    // You MAY need to edit this function
    ensureCapacity(mSize + 1);
    if (aux == 0) {
        mData[(mFront + mSize) % mCap] = element;
    } else {
        mData[(mFront - 1 + mCap) % mCap] = element;
        mFront = (mFront - 1 + mCap) % mCap;
    }
    mSize++;
}

template <typename T>
void CP::queue<T>::pop() {
    // You MAY need to edit this function
    if (aux == 0) {
        mFront = (mFront + 1) % mCap;
    }
    mSize--;
}

#endif