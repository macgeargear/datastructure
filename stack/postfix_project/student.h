#ifndef __STUDENT_H__
#define __STUDENT_H__
#include <map>
#include <stack>
#include <vector>

using namespace std;

int eval_postfix(vector<pair<int, int>> v) {
    // WRITE YOUR CODE HERE
    // DON"T FORGET TO RETURN THE RESULT
    int res = 0;
    stack<int> st;
    for (auto [f, s] : v) {
        if (f == 1) {
            st.push(s);
        } else if (f == 0) {
            int a = st.top();
            st.pop();
            int b = st.top();
            st.pop();
            if (s == 0) {
                res = b + a;
            } else if (s == 1) {
                res = b - a;
            } else if (s == 2) {
                res = b * a;
            } else if (s == 3) {
                res = b / a;
            }
            st.push(res);
        }
    }
    return st.top();
}

// 6
// res: 6

#endif
