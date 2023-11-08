#include <iostream>
#include <set>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    set<int> s;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        if (x >= 1 && x <= n) {
            s.insert(x);
        }
    }
    if (s.size() == n) {
        cout << "YES";
    } else {
        cout << "NO";
    }
}