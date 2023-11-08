#include <algorithm>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <vector>
using namespace std;

int get_second_min(stack<int> &s) {
    // write only in this function, do not declare static
    stack<int> tmp;
    vector<int> v;

    int mn = 2e9, second_mn = 2e9;
    while (!s.empty()) {
        tmp.push(s.top());
        v.push_back(s.top());
        s.pop();
    }

    for (auto x : v) {
        mn = min(mn, x);
    }

    for (auto x : v) {
        if (x > mn && second_mn > x) {
            second_mn = min(x, second_mn);
        }
    }

    while (!tmp.empty()) {
        s.push(tmp.top());
        tmp.pop();
    }

    return second_mn;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    // repeat n-1 times
    for (int last = 1; last < n; last += 1) {
        stack<int> s;
        // build s;
        bool distinct = false;
        for (int i = last; i >= 0; i--) {
            s.push(v[i]);
            if (v[i] != v[0])
                distinct = true;
        }
        cout << "--use v[" << last << "] to v[0] --"
             << "\n";
        if (distinct) {
            // call get_second_min if we have at least 2 distinct value
            int answer = get_second_min(s);
            // print result and s
            cout << "result is " << answer << "\n";
            cout << "size of s is " << s.size() << "\n"
                 << "member of s are ";
            while (s.size() > 0) {
                cout << s.top() << " ";
                s.pop();
            }
            cout << "\n";
        } else {
            cout << "skip because s has only one value\n\n\n";
        }
    }
    return 0;
}