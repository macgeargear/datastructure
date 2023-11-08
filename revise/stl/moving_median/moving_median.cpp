#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, w;
    cin >> n >> w;
    vector<int> v, tmp;

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        v.push_back(x);
    }

    for (int i = 0; i <= w; i++) {
        tmp.push_back(v[i]);
    }

    sort(tmp.begin(), tmp.end());
    cout << tmp[w / 2] << " ";

    for (int i = w + 1; i < n; i++) {
        tmp.erase(lower_bound(tmp.begin(), tmp.end(), v[i - w - 1]));
        tmp.insert(lower_bound(tmp.begin(), tmp.end(), v[i]), v[i]);
        cout << tmp[w / 2] << " ";
    }
}
