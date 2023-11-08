#include <iostream>
#include <set>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, a;
    cin >> n >> a;

    set<int> s = {a};
    int i = a;
    while (i < n) {
        if (s.find(i) != s.end()) {
            if (2 * i + 1 < n)
                s.insert(2 * i + 1);
            if (2 * i + 2 < n)
                s.insert(2 * i + 2);
        }
        i++;
    }

    cout << s.size() << "\n";
    for (auto &x : s) {
        cout << x << " ";
    }
}