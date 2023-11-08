#include <math.h>

#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    if (n == 1) {
        cout << 0;
        return 0;
    }
    int res = pow(2, (int)(log2(n)) + 1) - n;
    // cout << "pow: " << pow(2, (int)(log2(n)) + 1) << "\n";
    cout << res;
}