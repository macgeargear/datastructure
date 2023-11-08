#include <cassert>
#include <iostream>
#include <stdexcept>
#include <string>

#include "student.h"
#include "vector.h"

using std::cin;
using std::cout;
using std::endl;
using std::string;

int main() {
    int n, a, b;
    size_t k;
    cin >> n >> a >> b >> k;
    CP::vector<int> v(n);
    for (int i = 0; i < n; i++)
        v[i] = i;
    v.rotate(v.begin() + a, v.begin() + b, k);
    for (auto &x : v)
        cout << x << " ";
    cout << endl;
}
