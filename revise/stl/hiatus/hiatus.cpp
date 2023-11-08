#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> write = {{-1, -1}};
    for (int i = 0; i < n; i++) {
        int y, m;
        cin >> y >> m;
        write.emplace_back(y, m);
    }

    sort(write.begin(), write.end());

    for (int i = 0; i < m; i++) {
        pair<int, int> query;
        cin >> query.first >> query.second;
        auto it = --upper_bound(write.begin(), write.end(), query);
        if (*it == query) {
            cout << "0 0 ";
        } else {
            cout << it->first << " " << it->second << " ";
        }
    }
}