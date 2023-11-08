#include <iomanip>
#include <iostream>
#include <map>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout << std::fixed << std::setprecision(2);
    int n;
    cin >> n;
    map<string, pair<int, int>> teach, subj;
    for (int i = 0; i < n; i++) {
        string s, t;
        int score;
        cin >> s >> t >> score;
        teach[t].first += score;
        teach[t].second++;

        subj[s].first += score;
        subj[s].second++;
    }

    for (auto &[k, v] : subj) {
        cout << k << " " << (v.first + 0.0) / v.second << "\n";
    }
    for (auto &[k, v] : teach) {
        cout << k << " " << (v.first + 0.0) / v.second << "\n";
    }
}