#include <vector>
using namespace std;

template <typename T>
vector<T> Union(const vector<T>& A, const vector<T>& B) {
    vector<T> v(A.begin(), A.end());
    bool check[100000] = {false};
    for (auto& x : A) {
        check[x] = true;
    }
    for (auto& x : B) {
        if (!check[x])
            v.push_back(x);
    }

    return v;
}

template <typename T>
vector<T> Intersect(const vector<T>& A, const vector<T>& B) {
    vector<T> v;
    bool check[100000] = {false};
    for (auto& x : B)
        check[x] = true;
    for (auto& x : A)
        if (check[x])
            v.push_back(x);
    return v;
}
