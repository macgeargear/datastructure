#include <iostream>
#include <map>
#include <set>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    unordered_map<int, int> prod;
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        prod[x] = 0;
    }
}