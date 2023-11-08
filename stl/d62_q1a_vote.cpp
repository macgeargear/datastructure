#include <algorithm>
#include <iostream>
#include <map>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, k;
    cin >> n >> k;
    map<string, int> map;
    vector<int> score;

    while (n--) {
        string s;
        cin >> s;
        map[s]++;
    }

    for (auto &m : map) {
        score.push_back(m.second);
    }
    sort(score.begin(), score.end());

    int min_score = 2e9;
    for (auto &m : map) {
        min_score = min(min_score, m.second);
    }

    if (map.size() < k) {
        cout << min_score;
        return 0;
    }

    cout << score[score.size() - k];
}