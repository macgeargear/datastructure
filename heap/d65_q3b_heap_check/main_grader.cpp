#include "student.h"
#include <iostream>
#include <string>
#include <cassert>

using std::cin;
using std::cout;
using std::string;

// force no #include <algorithm>
//namespace std {
//template <typename _RandomAccessIterator>
//bool is_heap(_RandomAccessIterator __first, _RandomAccessIterator __last) {
//  assert(false);
//}
//} // namespace std


template <typename T>
class CompareKere {
  int bias;

public:
  CompareKere() : bias(1) {}
  // Extra naughty
  CompareKere(int bias) : bias(bias) {}
  bool operator()(T lhs, T rhs) {
    auto l = lhs.crbegin();
    auto r = rhs.crbegin();
    if (bias >= 0) {
      while (l != lhs.crend() && r != rhs.crend()) {
        if (*l == *r) {
          ++l;
          ++r;
        } else {
          return *l < *r;
        }
      }
      return l == lhs.crend();
    } else {
      while (l != lhs.crend() && r != rhs.crend()) {
        if (*l == *r) {
          ++l;
          ++r;
        } else {
          return *r < *l;
        }
      }
      return r == rhs.crend();
    }
  }
};

template <typename T, typename Comp>
void test(int mSize, const Comp c = Comp()) {
  T* data = new T[mSize];
  for (int i = 0; i < mSize; ++i)
    cin >> data[i];
  CP::priority_queue<T, Comp> q(data, mSize, mSize, c);

  if (q.check())
    cout << "VALID"
         << "\n";
  else
    cout << "INVALID"
         << "\n";
}

template <typename T>
void grader_primitive() {
  int t;
  cin >> t;
  while (t--) {
    int mSize, comp;
    cin >> mSize >> comp;

    if (comp == 1) {
      test<T, std::less<T>>(mSize);
    } else {
      test<T, std::greater<T>>(mSize);
    }
  }
}

template <typename T>
void grader_class() {
  int t;
  cin >> t;
  while (t--) {
    int mSize, comp;
    cin >> mSize >> comp;

    if (comp == 1) {
      test<T, std::less<T>>(mSize);
    } else if (comp == 2) {
      test<T, std::greater<T>>(mSize);
    } else if (comp == 3) {
      test<T, CompareKere<T>>(mSize);
    } else {
      test<T, CompareKere<T>>(mSize, CompareKere<T>(-1));
    }
  }
}

int main() {
  std::ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int type, comp;
  std::cin >> type;

  if (type == 1) {
    grader_primitive<int>();
  }
  if (type == 2) {
    grader_class<std::string>();
  }

  cout << "DONE baiuf90ajisndojlksad";
}
