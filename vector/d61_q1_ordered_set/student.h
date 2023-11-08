#include <iostream>
#include <set>
#include <unordered_set>
#include <vector>
using namespace std;

template <typename T>
vector<T> Union(const vector<T>& A, const vector<T>& B) {
    bool found[1000000] = {false};
    vector<T> res(A.begin(), A.end());
    for (auto& x : A) {
        found[x] = true;
    }
    for (auto& x : B) {
        if (!found[x])
            res.push_back(x);
    }
    return res;
}

template <typename T>
vector<T> Intersect(const vector<T>& A, const vector<T>& B) {
    bool found[1000000] = {false};
    vector<T> res;
    for (auto& x : B)
        found[x] = true;
    for (auto& x : A)
        if (found[x])
            res.push_back(x);
    return res;
}
