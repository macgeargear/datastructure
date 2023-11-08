#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    long long n;
    int k;
    cin >> n >> k;
    n--;
    if (k == 1) {
        cout << n;
        return 0;
    }

    int h = 0;
    while (n > 0) {
        n = (n - 1) / k;
        h++;
    }

    cout << h;
}