#include <algorithm>
#include <iostream>
#include <set>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    vector<int> v1, v2;
    set<int> ans;

    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        v1.push_back(x);
    }
    for (int i = 0; i < m; i++) {
        int x;
        cin >> x;
        v2.push_back(x);
    }
    sort(v2.begin(), v2.end());

    for (auto &x : v1) {
        bool found = binary_search(v2.begin(), v2.end(), x);
        if (found)
            ans.insert(x);
    }

    for (auto &x : ans)
        cout << x << " ";
}