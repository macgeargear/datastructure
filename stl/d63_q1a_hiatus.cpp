#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    vector<pair<int, int>> data;
    data.push_back(pair<int, int>(-1, -1));
    int N, M;
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        int y, m;
        cin >> y >> m;
        data.push_back(pair<int, int>(y, m));
    }
    sort(data.begin(), data.end());
    while (M--) {
        pair<int, int> query;
        cin >> query.first >> query.second;
        bool found = false;
        bool found_before = false;
        int res_y, res_m;
        auto it = --upper_bound(data.begin(), data.end(), query);
        if (*it == query) {
            cout << "0 0 ";
        } else {
            cout << it->first << " " << it->second << " ";
        }
    }
}
/*
1: 10
3: 1, 2
4: 5, 11
7: 5
8: 5
9: 6,2
10: 9
*/

/*

*/