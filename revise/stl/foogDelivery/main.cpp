#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    int curr = 0;
    cin >> n >> m;
    vector<int> query(m);
    vector<int> goal;
    for (int i = 0; i < m; i++)
        cin >> query[i];

    queue<int> fish, dot;
    for (int i = 0; i < n; i++) {
        int t;
        cin >> t;
        if (t == 1) {
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
                    goal.push_back(curr);
                    fish.pop();
                } else if (fish.front() < dot.front()) {
                    curr += fish.front();
                    fish.pop();
                    goal.push_back(curr);
                } else {
                    curr += dot.front();
                    dot.pop();
                    goal.push_back(curr);
                }
            } else if (!fish.empty()) {
                curr += fish.front();
                goal.push_back(curr);
                fish.pop();
            } else {
                curr += dot.front();
                dot.pop();
                goal.push_back(curr);
            }
        }
    }

    for (auto &q : query) {
        auto it = lower_bound(goal.begin(), goal.end(), q);
        if (it == goal.end())
            cout << "-1 ";
        else
            cout << it - goal.begin() + 1 << " ";
    }
}