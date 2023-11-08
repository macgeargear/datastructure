#include <iostream>
using namespace std;


int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int h,m,x;
    
    cin >> h >> m;
    cin >> x;

    int carry = 0;
    int _m = x+m;
    while (_m >= 60) {
        _m -= 60;
        carry += 1;
    }
    
    int _h = h + carry;
    while (_h >= 24) {
        _h -= 24;
    } 


    if (_h < 10 && _m < 10) {
        printf("0%d 0%d", _h, _m);
    } else if (_h < 10) {
        printf("0%d %d", _h, _m);
    } else if (_m < 10) {
        printf("%d 0%d", _h, _m);
    } else {
        printf("%d %d", _h, _m);
    }

}