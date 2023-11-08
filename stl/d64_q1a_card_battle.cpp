#include <algorithm>
#include <iostream>
#include <map>

using namespace std;

int main() {
    int n, m, cnt = 1;
    map<int, int> card;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        card[x]++;
    }

    for (int i = 0; i < m; i++) {
        int nums;
        cin >> nums;
        bool pass = true;
        while (nums--) {
            int x;
            cin >> x;
            auto ub = card.upper_bound(x);
            if (ub == card.end()) {
                cout << cnt;
                return 0;
            } else {
                card[ub->first]--;
            }
            if (card[ub->first] <= 0) {
                card.erase(ub->first);
            }
        }
        cnt++;
    }
    cout << cnt;

    return 0;
}