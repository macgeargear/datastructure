#include <iostream>
#include <map>
using namespace std;
#define ll long long

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    map<ll, ll> map;
    cin >> n >> m;
    while (n--) {
        ll f, s;
        cin >> f >> s;
        map[s] = f;
    }

    while (m--) {
        ll a, b;
        cin >> a >> b;
        if (a == b) {
            cout << "NO"
                 << "\n";
            continue;
        }
        if (map.find(a) == map.end() || map.find(b) == map.end()) {
            cout << "NO"
                 << "\n";
            continue;
        }
        ll f_a = map[a];
        ll f_b = map[b];
        if (map.find(f_a) == map.end() || map.find(f_b) == map.end()) {
            cout << "NO"
                 << "\n";
            continue;
        }
        ll g_a = map[f_a];
        ll g_b = map[f_b];
        if (g_a == g_b) {
            cout << "YES"
                 << "\n";
            continue;
        } else {
            cout << "NO"
                 << "\n";
            continue;
        }
    }
}

/*
2 - 1
3 - 1
20 - 2
30 - 3
21 - 2

2 - 1
30 - 2
20 - 30 -> 2, 3 -> 1, 1
20 - 20
*/