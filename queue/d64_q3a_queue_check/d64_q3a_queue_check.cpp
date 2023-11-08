#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    while (n--) {
        int mFront, mSize, mCap, last, correction;
        cin >> mFront >> mSize >> mCap >> last >> correction;
        int _last = (mFront + mSize) % mCap;
        if (last == _last && mCap >= mSize && mFront < mCap) {
            cout << "OK\n";
            continue;
        }

        cout << "WRONG ";
        if (correction == 0) {
            cout << "\n";
        } else {
            if (correction == 1) {  // mFront
                cout << (last + (mCap - mSize)) % mCap << "\n";
            } else if (correction == 2) {  // mSize
                if (mFront < last) {
                    cout << last - mFront << "\n";
                } else if (mFront == last) {
                    cout << "0\n";
                } else {
                    cout << mCap - mFront + last << "\n";
                }
            } else if (correction == 3) {  // mCap
                if (mFront < last) {
                    cout << mFront + mSize + 1 << "\n";
                } else {
                    cout << (mFront - last) + mSize << "\n";
                }
            } else {  // last
                cout << _last << "\n";
            }
        }
    }
}