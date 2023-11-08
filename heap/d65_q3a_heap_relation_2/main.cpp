#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

long long findH(long long k, long long a) {
    int h = 0;
    while (a > 0) {
        a = (a - 1) / k;
        h++;
    }
    return h;
}

int relation(long long S, long long a, long long b) {
    long long p, q;
    p = min(a, b);
    q = max(a, b);
    if (p == q)
        return 4;
    if ((q - 1) / S == p)
        return 1;
    if (p == 0)
        return 2;
    while (q > p) {
        q = (q - 1) / S;
    }
    if (q == p)
        return 2;
    long long h_a = findH(S, a);
    long long h_b = findH(S, b);
    if (h_a == h_b)
        return 4;
    return 3;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    long long S, a, b;
    cin >> n;
    while (n--) {
        cin >> S >> a >> b;
        cout << relation(S, a, b) << " ";
    }
    cout << endl;
}