#include <algorithm>
#include <iostream>
#include <map>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    map<int, int> cards;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        cards[x]++;
    }

    int round = 1;
    for (int round = 1; round <= m; round++) {
        int nums;
        cin >> nums;
        for (int j = 0; j < nums; j++) {
            int x;
            cin >> x;
            auto it = cards.upper_bound(x);
            if (it != cards.end()) {
                cards[it->first] -= 1;
                if (cards[it->first] == 0) {
                    cards.erase(it);
                }
            } else {
                cout << round;
                return 0;
            }
            // cout << "rounds: " << round << "\n";
        }
    }
    cout << round;
}