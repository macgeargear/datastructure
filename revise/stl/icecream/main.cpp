#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, m, start;
    cin >> n >> m >> start;

    vector<int> money(100000);
    money[0] = start;
    vector<pair<int, int>> change(n), query(m);

    for (int i = 0; i < n; i++) {
        int a, s;
        cin >> a >> s;
        change[i] = make_pair(a, s);
    }

    int idx = 0;
    for (int i = 1; i < 100000; i++) {
        if (i == change[idx].first) {
            start = change[idx].second;
            idx++;
        }
        money[i] = money[i - 1] + start;
    }

    for (int i = 0; i < m; i++) {
        int p, x;
        cin >> p >> x;
        query[i] = make_pair(p, x);
    }

    for (auto &[price, day] : query) {
        if (money[day] < price) {
            int i =
                lower_bound(money.begin(), money.end(), price + money[day]) -
                money.begin();
            cout << i << " ";
        } else {
            int i =
                lower_bound(money.begin(), money.end(), price) - money.begin();
            cout << i << " ";
        }
    }
}