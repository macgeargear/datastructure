#include <stdio.h>
#include <stdlib.h>

#include <iostream>
#include <stdexcept>
#include <vector>

#include "list_grader.h"
#include "student.h"

// #pragma once

bool check(CP::list<int> &l, CP::list<int> &check) {
    bool ok = true;
    // report result
    if (check.size() != l.size()) {
        printf("Size is wrong\n");
        ok = false;
    }

    // check "next" pointer
    CP::list<int>::iterator it1, it2;
    it1 = l.begin();
    it2 = check.begin();
    for (size_t i = 0; i < check.size(); i++) {
        if (*it1 != *it2) {
            printf("wrong data expecting %d got %d\n", *it2, *it1);
            ok = false;
        }
        it1++;
        it2++;
    }
    if (it1 != l.end()) {
        printf("wrong end() for l\n");
        ok = false;
    }

    // check "prev" pointer
    it1 = l.end();
    it2 = check.end();
    for (size_t i = 0; i < check.size(); i++) {
        it1--;
        it2--;
        if (*it1 != *it2) {
            printf("wrong data expecting %d got %d\n", *it2, *it1);
            ok = false;
        }
    }
    if (it1 != l.begin()) {
        printf("wrong begin() for l\n");
        ok = false;
    }
    return ok;
}

int main() {
    int n;
    size_t pos;
    std::cin >> n >> pos;
    std::vector<int> v(n);
    while (n--) {
        v[n] = n * 10;
    }

    // add value from v to l
    CP::list<int> l1;
    for (auto x : v)
        l1.push_back(x);

    // create it and pos
    auto it = l1.begin();
    for (size_t i = 0; i < pos; i++) {
        it++;
    }

    // call the split 1e5 times
    CP::list<int> l2;
    for (int i = 0; i < 1e5; i++) {
        l2 = l1.split(it, pos);
        it = l1.end();
        it--;
        l1.concat(l2);
        it++;
    }
    l2 = l1.split(it, pos);

    // check
    // create the correct result in O(N)
    CP::list<int> check1, check2;
    for (size_t i = 0; i < v.size(); i++) {
        if (i < pos)
            check1.push_back(v[i]);
        if (i >= pos)
            check2.push_back(v[i]);
    }

    printf("checking l1 (the original list)\n");
    bool b1 = check(l1, check1);
    printf("checking l2 (the returned list)\n");
    bool b2 = check(l2, check2);

    if (b1 && b2) {
        printf("CONCLUSION: correct vaoierlkhtlkjhlg853;lhlsflkjsb\n");
    } else {
        printf("CONCLUSION: wrong\n");
    }

    return 0;
}
