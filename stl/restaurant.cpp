#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    vector<int> chef;
    // time, chef
    priority_queue<pair<int, int>> pq;
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        chef.push_back(x);
    }

    for (int i = 0; i < n; i++) {
        pq.push({-chef[i], chef[i]});
        cout << "0\n";
    }

    for (int i = n; i < m; i++) {
        int x = pq.top();
        pq.pop();
        cout << -x.first << "\n";
    }
}