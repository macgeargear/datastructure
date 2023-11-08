#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>
using namespace std;

string convert(string s, vector<int> k) {
    string res = "";
    for (int i = 0; i < s.size(); i++) {
        res += char('a' + (s[i] + k[i] - 'a') % 26);
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    set<string> db;
    vector<int> k;
    map<string, string> Map;
    int n, m, l;
    cin >> n >> m >> l;
    while (l--) {
        int s;
        cin >> s;
        k.push_back(s);
    }

    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        db.insert(s);
        Map[s] = convert(s, k);
    }

    while (m--) {
        string s;
        cin >> s;
        if (db.find(convert(s, k)) != db.end()) {
            cout << "Match"
                 << "\n";
        } else {
            cout << "Unknown"
                 << "\n";
        }
    }
}
