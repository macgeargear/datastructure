#include <algorithm>
#include <iostream>
#include <set>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> v;
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        v.push_back({x, y});
    }
    sort(v.begin(), v.end());
    int target;
    while (m--) {
        cin >> target;
        bool found = false;
        int l = 0, r = v.size() - 1;
        while (l <= r) {
            int mid = (l + r) / 2;
            if (target >= v[mid].first && target <= v[mid].second) {
                found = true;
                break;
            } else if (target < v[mid].first) {
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        if (found)
            cout << "1 ";
        else
            cout << "0 ";
    }
}