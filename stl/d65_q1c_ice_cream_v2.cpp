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

    int rate = start;

    for (int i = 0; i < m; i++) {
        int p, x;
        cin >> p >> x;
        query.push_back({p, x});
        lastDay = max(lastDay, x);
    }

    int change_ind = 0;
    for (int i = 1; i <= 100000; i++) {
        if (change.size() > 0 && i == change[change_ind].first) {
            rate = change[change_ind].second;
            change_ind++;
        }
        sum += rate;
        sum_arr.push_back(sum);
    }

    for (int i = 0; i < query.size(); i++) {
        int price = query[i].first;
        int day = query[i].second;
        if (sum_arr[day] < price) {
            int index = lower_bound(sum_arr.begin(), sum_arr.end(),
                                    price + sum_arr[day]) -
                        sum_arr.begin();
            cout << index << " ";
        } else {
            int d = lower_bound(sum_arr.begin(), sum_arr.end(), price) -
                    sum_arr.begin();
            cout << d << " ";
        }
    }
}
/*
2 5 3
4 2
6 5
--
11 3
12 3
13 3
200 4
200 5

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