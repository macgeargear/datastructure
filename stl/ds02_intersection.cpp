#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

void find(vector<int> v, int target, vector<int> &res) {
    int l = 0, r = v.size() - 1;
    while (l <= r) {
        int mid = (l + r) / 2;
        if (v[mid] == target) {
            res.push_back(target);
            return;
        } else if (v[mid] > target) {
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<int> v1, v2, res;
    while (n--) {
        int x;
        cin >> x;
        v1.push_back(x);
    }
    while (m--) {
        int x;
        cin >> x;
        v2.push_back(x);
    }

    sort(v1.begin(), v1.end());
    sort(v2.begin(), v2.end());

    for (auto &x1 : v1) {
        find(v2, x1, res);
    }

    for (int i = 0; i < res.size(); i++) {
        if (i == 0 || (res[i] != res[i - 1]))
            cout << res[i] << " ";
    }
}