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
            if (M.find(a) == M.end())
                continue;

            auto it = s.lower_bound({M[a], a});
            if (it != s.end()) {
                M[a] += b;
                s.erase(it);
                s.insert({M[a], a});
            } else {
                M[a] = b;
                s.insert({b, a});
            }
        } else {
            int k;
            cin >> k;
            auto it = s.lower_bound({k, 0});
            if (it == s.begin()) {
                cout << "NONE\n";
            } else {
                it--;
                if (it->first == 0)
                    cout << "NONE\n";
                else
                    cout << it->second << "\n";
            }
        }
    }
}

/*
3 10
1 2 3
1 999 10
1 3 5
1 2 3
1 1 4
*/