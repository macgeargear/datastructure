#include <iostream>
#include <map>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    map<int, int> map;
    cin >> n >> m;
    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        map[arr[i]]++;
    }

    int target;
    while (m--) {
        cin >> target;
        bool found = false;
        for (auto &m : map) {
            int diff = target - m.first;
            if (diff == m.first) {
                if (m.second > 1) {
                    found = true;
                    break;
                }
            } else {
                if (map.find(diff) != map.end()) {
                    found = true;
                    break;
                }
            }
        }
        if (found) {
            cout << "YES"
                 << "\n";
        } else {
            cout << "NO"
                 << "\n";
        }
    }
}