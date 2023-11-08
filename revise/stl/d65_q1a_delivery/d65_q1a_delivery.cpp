#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, m, curr = 0;
    cin >> n >> m;
    vector<int> sums, query;
    queue<int> fish, dot;

    for (int i = 0; i < m; i++) {
        int x;
        cin >> x;
        query.push_back(x);
    }

    for (int i = 0; i < n; i++) {
        int op;
        cin >> op;
        if (op == 1) {
            int a, b;
            cin >> a >> b;
            if (a == 1) {
                fish.push(b);
            } else {
                dot.push(b);
            }
        } else {
            if (!fish.empty() && !dot.empty()) {
                if (fish.front() == dot.front()) {
                    curr += fish.front();
                    fish.pop();
                } else if (fish.front() < dot.front()) {
                    curr += fish.front();
                    fish.pop();
                } else {
                    curr += dot.front();
                    dot.pop();
                }
                sums.push_back(curr);
            } else if (!fish.empty()) {
                curr += fish.front();
                fish.pop();
                sums.push_back(curr);
            } else {
                curr += dot.front();
                dot.pop();
                sums.push_back(curr);
            }
        }
    }

    for (auto &q : query) {
        auto it = lower_bound(sums.begin(), sums.end(), q);
        if (it != sums.end()) {
            cout << it - sums.begin() + 1 << " ";
        } else {
            cout << -1 << " ";
        }
    }
}