#include <iomanip>
#include <iostream>
#include <map>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cout << std::fixed << std::setprecision(2);
    int n;
    cin >> n;
    map<string, pair<int, int>> teach, subj;
    while (n--) {
        string t, s;
        int score;
        cin >> s >> t >> score;
        teach[t].first += score;
        teach[t].second++;
        subj[s].first += score;
        subj[s].second++;
    }

    for (auto &s : subj) {
        cout << s.first << " " << (s.second.first + 0.0) / s.second.second
             << "\n";
    }

    for (auto &t : teach) {
        cout << t.first << " " << (t.second.first + 0.0) / t.second.second
             << "\n";
    }
}