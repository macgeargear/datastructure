#include <cmath>
#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    long long n;
    int k;
    cin >> n >> k;
    if (k == 1) {
        cout << n - 1;
        return 0;
    }

    long long cnt = 0;
    long long sum = 0;
    int t = 0;
    while (sum < n) {
        sum += pow(k, t++);
        cnt++;
    }
    cout << cnt - 1 << "\n";
    return 0;
}