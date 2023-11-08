#include <iostream>
#include <map>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    map<string, int> map;
    cin >> n;
    while (n--) {
        string s;
        cin >> s;
        map[s]++;
    }

    for (auto &m : map) {
        if (m.second > 1) {
            cout << m.first << " " << m.second << "\n";
        }
    }
}