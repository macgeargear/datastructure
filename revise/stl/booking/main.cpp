#include <algorithm>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    vector<pair<string, int>> ticket(n);
    for (int i = 0; i < n; i++) {
        string a, s;
        cin >> a >> s;
        ticket[i] = make_pair(a + "-" + s, 1);
    }
    sort(ticket.begin(), ticket.end());

    for (int i = 0; i < m; i++) {
        int t;
        cin >> t;
        vector<int> query(t);
        bool done = true;
        for (auto &e : query) {
            string a, s;
            cin >> a >> s;
            if (!done)
                continue;
            auto q = make_pair(a + "-" + s, 1);
            auto it = lower_bound(ticket.begin(), ticket.end(), q);
            if (*it != q)
                done = false;
            e = it - ticket.begin();
        }
        if (done) {
            for (auto &q : query)
                ticket[q].second--;
        }
        cout << (done ? "YES\n" : "NO\n");
    }
}