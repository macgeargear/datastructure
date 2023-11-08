#include <algorithm>
#include <iostream>
#include <map>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    map<int, int> Max;
    map<int, int> Min;
    cin >> n >> m;

    vector<pair<int, int>> add(n);
    for (int i = 0; i < m; i++) {
        Max[i] = 1;
    }
    Min[1] = m;

    // power
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        add[i].second = x;
    }

    // type
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        add[i].first = x;
    }

    // (type, power)

    for (int i = 0; i < n; i++) {
        int type = add[i].first;
        int power = add[i].second;

        if (power > Max[type]) {
            Min[Max[type]]--;
            if (Min[Max[type]] == 0)
                Min.erase(Max[type]);
            Max[type] = power;
            Min[power]++;
        }

        cout << (*Min.begin()).first << " ";
    }
}

/*
map
0: 1->10
1: 5

map:
1: 0 // erase
5: 1
10: 1
*/

/*
team:
0: (1, 0, 10, 12)
power: 12
--
1: (1, 5, 15)
power: 15
--
strenght: 1 1 5 10 12
*/