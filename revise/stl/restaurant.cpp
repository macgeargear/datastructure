#include <iostream>
#include <queue>
#include <vector>
using namespace std;

typedef pair<int, int> pii;

bool comp(pii &left, pii &right) {
    if (left.first == right.first) {
        return left.first < right.second;
    }
    return left.first < right.second;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    priority_queue<pii, vector<pii>, greater<pii>> pq;

    int n, m;
    vector<int> chef;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        chef.push_back(x);
        pq.push({0, chef[i]});
    }

    // first = time-to-current-done
    // second = time-to-wait-chef
    for (int i = 0; i < m; i++) {
        auto curr = pq.top();
        pq.pop();

        cout << curr.first << "\n";

        int time_to_done = curr.first + curr.second;
        int time_to_wait = curr.second;

        pq.push({time_to_done, time_to_wait});
    }
}

/*
chef: 1 3 4

i=0
pq:
curr:

--

*/