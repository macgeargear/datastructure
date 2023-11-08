#include <stdlib.h>
#include <time.h>

#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>

#include "queue.h"
#include "student.h"

template <typename T>
void print(std::vector<std::pair<T, size_t>> &result) {
    for (auto &x : result) {
        std::cout << x.first << " " << x.second << "\n";
    }
}

int neg() {
    return (rand() % 2) ? 1 : -1;
}

// Blank k
bool test1() {
    std::vector<int> k;
    CP::queue<int> q;
    q.push(3);
    q.push(-9);
    q.push(1000);
    q.push(5001);
    q.push(404);
    q.push(99);
    auto r = q.count_multi(k);
    print(r);
    return true;
}

// Blank q
bool test2() {
    std::vector<int> k;
    CP::queue<int> q;
    k.push_back(3);
    k.push_back(-9);
    k.push_back(1000);
    k.push_back(5001);
    k.push_back(404);
    k.push_back(99);

    auto r = q.count_multi(k);
    print(r);
    return true;
}

// Exists and not Exists
bool test3() {
    std::vector<int> k;
    CP::queue<int> q;
    q.push(50);
    q.push(50);
    q.push(10);
    q.push(1);
    for (int i = 0; i <= 11; i++)
        q.push(-99);
    for (int i = 0; i <= 15; i++)
        q.push(5001);
    for (int i = 0; i <= 1000; i++)
        q.push(1000000000);
    q.push(404);
    q.push(99);
    k.push_back(-2);
    k.push_back(404);
    k.push_back(50);
    k.push_back(1000000000);
    k.push_back(11111);
    k.push_back(-99);
    auto r = q.count_multi(k);
    print(r);
    return true;
}

// 2000 elements, random valid in k
bool test4() {
    std::vector<int> k;
    CP::queue<int> q;
    for (int i = 0; i < 2000; i++) {
        int rndx = neg() * rand();
        q.push(rndx);
        if ((rand() % 50) == 0)
            k.push_back(rndx);
        else if (rand() % 2)
            k.push_back(neg() * rand());
    }
    auto r = q.count_multi(k);
    print(r);
    return true;
}

// All not existed in k
bool test5() {
    std::vector<int> k;
    CP::queue<int> q;
    q.push(50);
    q.push(50);
    q.push(-10);
    q.push(1);
    for (int i = 0; i <= 11; i++)
        q.push(-99);
    for (int i = 0; i <= 15; i++)
        q.push(5001);
    q.push(404);
    q.push(99);
    k.push_back(-55552);
    k.push_back(5066);
    k.push_back(11111);
    k.push_back(-999);
    auto r = q.count_multi(k);
    print(r);
    return true;
}

// |k|, |q| = 2000 and same
bool test6() {
    std::vector<int> k;
    CP::queue<int> q;

    int rndx = rand();
    for (int i = 0; i < 10000; i++) {
        k.push_back(rndx);
        q.push(rndx);
    }
    auto r = q.count_multi(k);
    print(r);
    return true;
}

// |k|, |q| = 2000 and not same
bool test7() {
    std::vector<int> k;
    CP::queue<int> q;

    int rndx, rndy;
    for (int i = 0; i < 10000; i++) {
        rndx = rand();
        rndy = rand();
        k.push_back(rndx);
        q.push(rndy);
    }
    auto r = q.count_multi(k);
    print(r);
    return true;
}

// Multiple Multi-value with int 1e9
bool test8() {
    std::vector<int> k;
    CP::queue<int> q;
    for (int i = 0; i < 10000; i++) {
        if (rand() % 4)
            q.push(1000000000);
        else
            q.push(rand());
        if (rand() % 2) {
            if ((rand() % 100) == 0) {
                k.push_back(1000000000);
            } else {
                k.push_back(rand());
            }
        }
    }
    auto r = q.count_multi(k);
    print(r);
    return true;
}

// Multiple Multi-value with -1e9
bool test9() {
    std::vector<int> k;
    CP::queue<int> q;

    for (int i = 0; i < 50000; i++) {
        if (rand() % 4)
            q.push(-1000000000);
        else
            q.push(neg() * rand());
        if (rand() % 2) {
            if ((rand() % 100) == 0) {
                k.push_back(-1000000000);
            } else {
                k.push_back(neg() * rand());
            }
        }
    }

    auto r = q.count_multi(k);
    print(r);
    return true;
}

// Test Multi-value
bool test10() {
    std::vector<int> k;
    CP::queue<int> q;

    int x, tmp = 0;
    for (int i = 0; i < 50000; i++) {
        x = rand();
        k.push_back(neg() * x);
        if ((rand() % 3) == 0 && q.size() > 0) {
            x = tmp;
        }
        if ((rand() % 10) == 0)
            tmp = x;
        q.push(neg() * x);
    }

    auto r = q.count_multi(k);
    print(r);
    return true;
}

bool test11() {
    std::vector<int> k;
    CP::queue<int> q;

    int x, tmp = 0;
    for (int i = 0; i < 200000; i++) {
        x = rand();
        k.push_back(neg() * x);
        if ((rand() % 3) == 0 && q.size() > 0) {
            x = tmp;
        }
        if ((rand() % 10) == 0)
            tmp = x;
        q.push(neg() * x);
    }

    auto r = q.count_multi(k);
    print(r);
    return true;
}

bool test12() {
    std::vector<std::string> k;
    CP::queue<std::string> q;

    int x, tmp = 0;
    for (int i = 0; i < 200000; i++) {
        x = rand();
        k.push_back(std::to_string(neg() * x));
        if ((rand() % 3) == 0 && q.size() > 0) {
            x = tmp;
        }
        if ((rand() % 10) == 0)
            tmp = x;
        q.push(std::to_string(neg() * x));
    }

    auto r = q.count_multi(k);
    print(r);
    return true;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    srand(1453);
    int i;
    std::cin >> i;
    switch (i) {
        case 1:
            std::cout << (test1() ? "OK gq3;4o8y9gpa;zibas;d" : "WRONG")
                      << std::endl;
            break;
        case 2:
            std::cout << (test2() ? "OK gq3;4o8y9gpa;zibas;d" : "WRONG")
                      << std::endl;
            break;
        case 3:
            std::cout << (test3() ? "OK gq3;4o8y9gpa;zibas;d" : "WRONG")
                      << std::endl;
            break;
        case 4:
            std::cout << (test4() ? "OK gq3;4o8y9gpa;zibas;d" : "WRONG")
                      << std::endl;
            break;
        case 5:
            std::cout << (test5() ? "OK gq3;4o8y9gpa;zibas;d" : "WRONG")
                      << std::endl;
            break;
        case 6:
            std::cout << (test6() ? "OK gq3;4o8y9gpa;zibas;d" : "WRONG")
                      << std::endl;
            break;
        case 7:
            std::cout << (test7() ? "OK gq3;4o8y9gpa;zibas;d" : "WRONG")
                      << std::endl;
            break;
        case 8:
            std::cout << (test8() ? "OK gq3;4o8y9gpa;zibas;d" : "WRONG")
                      << std::endl;
            break;
        case 9:
            std::cout << (test9() ? "OK gq3;4o8y9gpa;zibas;d" : "WRONG")
                      << std::endl;
            break;
        case 10:
            std::cout << (test10() ? "OK gq3;4o8y9gpa;zibas;d" : "WRONG")
                      << std::endl;
            break;
        case 11:
            std::cout << (test11() ? "OK gq3;4o8y9gpa;zibas;d" : "WRONG")
                      << std::endl;
            break;
        case 12:
            std::cout << (test12() ? "OK gq3;4o8y9gpa;zibas;d" : "WRONG")
                      << std::endl;
            break;
    }
}
