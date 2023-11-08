#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    while (m--) {
        int a, b;
        cin >> a >> b;
        if (a == b)
            cout << "a and b are the same node\n";
        else if (a < b) {
            while (b > a) {
                b = (b - 1) / 2;
            }
            if (a == b)
                cout << "a is an ancestor of b\n";
            else
                cout << "a and b are not related\n";
        } else {
            while (a > b) {
                a = (a - 1) / 2;
            }
            if (a == b)
                cout << "b is an ancestor of a\n";
            else
                cout << "a and b are not related\n";
        }
    }
}