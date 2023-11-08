#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, m, start;
    cin >> n >> m >> start;

    vector<pair<int, int>> change;
    vector<int> sum_arr = {start};
    vector<pair<int, int>> query;
    int sum = start;
    int lastDay = 0;
    for (int i = 0; i < n; i++) {
        int a, s;
        cin >> a >> s;
        change.push_back(pair<int, int>(a, s));
    }
    sort(change.begin(), change.end());

    int change_ind = 0;
    int rate = start;

    for (int i = 0; i < m; i++) {
        int p, x;
        cin >> p >> x;
        query.push_back(pair<int, int>(p, x));
        lastDay = max(lastDay, x);
    }
    for (int i = 1; i <= lastDay; i++) {
        if (change[change_ind].first == i) {
            rate = change[change_ind].second;
            change_ind++;
        }
        sum += rate;
        sum_arr.push_back(sum);
    }

    // for (int i = 0; i < sum_arr.size(); i++)
    //     cout << i << " " << sum_arr[i] << "\n";

    for (auto &[price, day] : query) {
        int ind = lower_bound(sum_arr.begin(), sum_arr.end(), price) -
                  sum_arr.begin();
        if (day < sum_arr.size() && sum_arr[day] >= price) {
            cout << ind << " ";
            continue;
        }
        if (day > sum_arr.size()) {
            // cout << "invalid day"
            //      << "\n";
            if (sum_arr[ind] >= price) {
                cout << ind << " ";
                continue;
            }
            // aldready scammed
            int current_sum = sum_arr.back();
            int current_day = sum_arr.size() - 1;
            int tmp_change_ind = change_ind;
            while (current_sum < price) {
                if (change[tmp_change_ind].first == current_day) {
                    rate = change[tmp_change_ind].second;
                    tmp_change_ind++;
                }
                if (current_day == day)
                    current_sum = 0;
                current_sum += rate;
                current_day++;
            }
            cout << current_day << " ";
            continue;
        }
        if (sum_arr[day] < price) {
            // cout << "invalid price";
            int tmp_change_ind = change_ind++;
            int current_sum = 0;
            int current_day = day;
            while (current_sum < price) {
                current_day++;
                if (change[tmp_change_ind].first == current_day) {
                    rate = change[tmp_change_ind].second;
                    tmp_change_ind++;
                }
                // cout << "rate: " << rate << "\n";
                // cout << " cursum " << current_sum << "\n";
                current_sum += rate;
                if (current_sum > price)
                    break;
            }
            cout << current_day << " ";
            continue;
        }
    }
}
/*
5 0
6 5
7 10
8 15

  200
*/

/*
sum:
rate: 3
--
start 3
day money cum
1    3 .   6
2    3 .   9
3    3 .   12
4    2 .   14
5    2 .   16
6    5 .   21
7    5 .   26

1 1000 -- 0
3 1000 -- 0
4 1000 --  1
12 1000 -- 3
13 1000 -- 4
14 1000 -- 4
15 1000 -- 5
*/