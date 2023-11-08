#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <vector>
using namespace std;

/*
using set
        user bid-price
        index = i th items

                (2, 100)
vector<int>
vector<set<pair<int,int>>>
set<pair<int,int>>
    price user
pq<int, int>

upper_bound({2, -2e9})


    item  piece
map<int, int>

    item     price user
map<int, vector<{int, int}>

---
        item   user  price
set<tuple<int, int, int>>

---
                    user  bid-price
vector<unordered_map<int, int>> m
vector<int> piece {3,1,4,2,3,1,} k
    0
[{1: 100, 2: 90, 3: 999}, {}, {}]

pq: (999, 3) (100, 1) (90, 2)

while (!pq.empty() && i< k) {
    auto curr = pq.top();
    answer[curr.2].push_back(i);
    pq.pop();
    i++;
}

vector<<vector<>> answer();

*/

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, m, a;
    cin >> n >> m >> a;

    for (int i = 0; i < n; i++)

        set<tuple<int, int, int>>
}

/*
Item
0 1
1 1
---
0: 1 | (100, 2) (10, 1)
1: 1 |

*/