#include <iostream>
#include <queue>
#include <unordered_map>
#include <vector>
using namespace std;
typedef pair<int, int> pii;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, m, Q;
    cin >> n >> m >> Q;

    vector<int> p(n + 1, 0);
    for (int i = 0; i < n; i++) {
        cin >> p[i + 1];
    }

    unordered_map<int, int> bidMap[n + 1];
    while (Q--) {
        char op;
        cin >> op;
        if (op == 'B') {
            int u, i, v;
            cin >> u >> i >> v;
            bidMap[i][u] = v;
        } else {
            int u, i;
            cin >> u >> i;
            auto it = bidMap[i].find(u);
            if (it != bidMap[i].end()) {
                bidMap[i].erase(it);
            }
        }
    }

    vector<int> ans[m + 1];
    for (int i = 1; i <= n; i++) {
        priority_queue<pii> pq;
        for (auto& [u, a] : bidMap[i]) {
            pii curr = make_pair(-a, -u);
            if (!pq.empty() and pq.top() > curr and pq.size() == p[i])
                pq.pop();
            if (pq.size() < p[i]) {
                pq.push(curr);
            }
        }
        while (!pq.empty()) {
            auto [a, u] = pq.top();
            ans[-u].push_back(i);
            pq.pop();
        }
    }

    for (int i = 1; i <= m; i++) {
        if (ans[i].size() == 0) {
            cout << "NONE\n";
            continue;
        }

        for (auto& x : ans[i]) {
            cout << x << " ";
        }
        cout << "\n";
    }

    return 0;
}