#include <iostream>
using namespace std;

long long findH(long long k, long long i) {
    int h = 0;
    while (i > 0) {
        i = (i - 1) / k;
        h++;
    }
    return h;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    while (n--) {
        long long s, a, b;
        cin >> s >> a >> b;
        long long x = std::min(a, b);
        long long y = std::max(a, b);
        long long h_x = findH(s, x);
        long long h_y = findH(s, y);
        int res;
        if ((y - 1) / s == x) {
            cout << "1 ";
            continue;
        }
        if (h_x == h_y) {
            cout << "4 ";
            continue;
        }
        while (y > x) {
            y = (y - 1) / s;
        }
        if (y == x) {
            cout << "2 ";
            continue;
        }
        cout << "3 ";
    }
}