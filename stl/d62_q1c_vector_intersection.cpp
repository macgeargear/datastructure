#include <iostream>
#include <set>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    set<int> s1, s2, res;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        s1.insert(x);
    }

    for (int i = 0; i < m; i++) {
        int x;
        cin >> x;
        s2.insert(x);
    }

    set_intersection(s1.begin(), s1.end(), s2.begin(), s2.end(),
                     std::inserter(res, res.begin()));

    for (auto &x : res)
        cout << x << " ";
}