#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, m, k;
    cin >> n >> m >> k;
    vector<int> arr;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        arr.push_back(x);
    }
    sort(arr.begin(), arr.end());

    int x, val;
    while (m--) {
        cin >> x;
        val = upper_bound(arr.begin(), arr.end(), x + k) -
              lower_bound(arr.begin(), arr.end(), x - k);
        cout << val << " ";
    }
}
