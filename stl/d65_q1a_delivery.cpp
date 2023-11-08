#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <vector>
using namespace std;

// a ร้าน
// 1 ปลาทอง
// 2 ดอทแมน
// b ยอดขาย

// ทำอาหาร 2

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    queue<int> store_fish, store_dot;
    int n, m, col_sum = 0;
    cin >> n >> m;
    vector<int> goals, sum, ans;

    for (int i = 0; i < m; i++) {
        int x;
        cin >> x;
        goals.push_back(x);
    }

    for (int i = 0; i < n; i++) {
        int op, a, b;
        cin >> op;
        if (op == 1) {
            cin >> a >> b;
            if (a == 1)
                store_fish.push(b);
            else
                store_dot.push(b);
        } else {
            if (!store_dot.empty() && !store_fish.empty()) {
                int price_dot = store_dot.front();
                int price_fish = store_fish.front();
                if (price_dot < price_fish) {
                    col_sum += price_dot;
                    store_dot.pop();
                } else {
                    col_sum += price_fish;
                    store_fish.pop();
                }
            } else if (!store_dot.empty()) {
                col_sum += store_dot.front();
                store_dot.pop();
            } else {
                col_sum += store_fish.front();
                store_fish.pop();
            }
            sum.push_back(col_sum);
        }
    }

    for (int &x : goals) {
        auto it = lower_bound(sum.begin(), sum.end(), x);
        if (it != sum.end())
            ans.push_back(it - sum.begin() + 1);
        else
            ans.push_back(-1);
    }

    for (int &x : ans) {
        cout << x << " ";
    }
}