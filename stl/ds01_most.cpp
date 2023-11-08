#include <iostream>
#include <map>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    map<string, int> m;
    while (n--) {
        string s;
        cin >> s;
        m[s]++;
    }

    map<string, int>::iterator it;
    int maxCount = -2e9;
    string s = "";
    for (it = m.begin(); it != m.end(); it++) {
        if (maxCount <= it->second) {
            maxCount = it->second;
            s = it->first;
        }
    }

    cout << s << " " << maxCount;
}