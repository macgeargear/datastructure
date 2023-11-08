#include <iostream>
#include <set>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    set<int> s;

    int n, a;
    cin >> n >> a;

    s.insert(a);
    for (int i = a; i < n; i++) {
        if (s.find(i) != s.end()) {
            if (i * 2 + 1 < n)
                s.insert(i * 2 + 1);
            if (i * 2 + 2 < n)
                s.insert(i * 2 + 2);
        }
    }

    cout << s.size() << "\n";
    for (auto &x : s)
        cout << x << " ";
}