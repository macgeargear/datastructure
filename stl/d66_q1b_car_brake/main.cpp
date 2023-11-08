#include <algorithm>
#include <iostream>
#include <map>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, m, k;
    cin >> n >> m >> k;

    vector<pair<int, int>> Q(m), d(n);

    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        d[i] = {a, b};
    }

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        Q[i] = {a, b};
    }
    sort(d.begin(), d.end());

    map<int, int> time, vel;
    time[0] = k;
    for (auto& [t, d] : d) {
        k -= d;
        time[t] = max(0, k);
    }

    for (auto it = time.begin(); it != --time.end(); it++) {
        auto i = it;
        i++;
        vel[it->second] = i->first;
    }
    vel[0] = d[n - 1].first + 1;

    for (auto& [a, q] : Q) {
        if (a == 1) {
            auto it = time.upper_bound(q);
            if (it == time.end())
                cout << "0\n";
            else
                cout << (--it)->second << "\n";
        } else {
            auto it = vel.lower_bound(q);
            if (it == vel.end())
                cout << "0\n";
            else
                cout << it->second << "\n";
        }
    }
}
