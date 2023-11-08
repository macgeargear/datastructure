#include <algorithm>
#include <iostream>
#include <set>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    set<pair<int, int>> s = {{3, 1}, {7, 2}, {7, 3}};
    auto it = s.upper_bound(make_pair(4, 0));
    cout << it->first << " " << it->second << "\n";
}