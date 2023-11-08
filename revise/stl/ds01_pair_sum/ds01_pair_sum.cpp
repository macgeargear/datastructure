#include <iostream>
#include <map>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    map<int, int> pairs;
    int n, m;
    cin >> n >> m;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        pairs[x]++;
    }
    for (int i = 0; i < m; i++) {
        int target;
        bool found = false;
        cin >> target;
        for (auto &pair : pairs) {
            int diff = target - pair.first;
            if (diff == pair.first) {
                if (pair.second > 1) {
                    found = true;
                    break;
                }
            } else {
                if (pairs.find(diff) != pairs.end()) {
                    found = true;
                    break;
                }
            }
        }
        if (found)
            cout << "YES"
                 << "\n";
        else
            cout << "NO"
                 << "\n";
    }
}
