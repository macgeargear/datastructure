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

        if (mFront < mCap && mCap >= mSize && last < mCap &&
            (mFront + mSize) % mCap == last) {
            cout << "OK\n";
            continue;
        }

        int ans;
        if (correction == 0) {
            cout << "WRONG\n";
            continue;
        } else if (correction == 1)
            ans = (last - mSize + mCap) % mCap;
        else if (correction == 2)
            ans = (last - mFront + mCap) % mCap;  // correct
        else if (correction == 3) {
            ans = (mFront < last) ? (mFront + mSize + 1)
                                  : (mFront - last + mSize);  // correct mCap
        } else if (correction == 4) {
            ans = (mFront + mSize) % mCap;  // correct last
        }
        cout << "WRONG " << ans << "\n";
    }
}