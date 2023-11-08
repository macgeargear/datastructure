#include <algorithm>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>

using namespace std;

void printt(set<pair<int, int>> &s) {
    for (auto &[k, v] : s) {
        cout << "amount " << k << " " << v << "\n";
    }
    cout << "-------\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    map<int, int> M;
    set<pair<int, int>> s;

    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        M[x] = 0;
        s.insert({0, x});
    }
    for (int i = 0; i < m; i++) {
        int t;
        cin >> t;
        if (t == 1) {
            int a, b;
            cin >> a >> b;
            if (M.find(a) == M.end()) {
                continue;
            }
            auto it = s.lower_bound(make_pair(M[a], a));
            if (it == s.end()) {
                s.insert(make_pair(b, a));
                M[a] = b;

            } else {
                M[a] += b;
                s.erase(it);
                s.insert({M[a], a});
            }
        } else {
            int k;
            cin >> k;
            auto it = s.lower_bound(make_pair(k, 0));
            if (it == s.begin())
                cout << "NONE\n";
            else {
                it--;
                if (it->first == 0)
                    cout << "NONE\n";
                else
                    cout << it->second << "\n";
            }
        }
    }
}