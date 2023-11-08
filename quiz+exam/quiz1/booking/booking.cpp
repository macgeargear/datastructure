#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;

typedef pair<std::string, int> psi;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<psi> seat;
    for (int i = 0; i < n; i++) {
        string a, b;
        cin >> a >> b;
        string code = a + "-" + b;
        seat.push_back({code, 1});
    }
    sort(seat.begin(), seat.end());
    for (int i = 0; i < m; i++) {
        int k = 0;
        cin >> k;
        vector<int> query(k);
        bool all = true;
        for (auto& e : query) {
            string a, b;
            cin >> a >> b;
            if (!all)
                continue;
            string code = a + "-" + b;
            auto p = make_pair(code, 1);
            auto it = lower_bound(seat.begin(), seat.end(), p);
            if (*it != p)
                all = false;
            e = it - seat.begin();
        }

        cout << (all ? "YES\n" : "NO\n");
        if (all) {
            for (auto& idx : query)
                seat[idx].second = 0;
        }
    }
}