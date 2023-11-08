#include <iostream>
using namespace std;

template <typename T>
class list {
protected:
    class node {
    public:
        T data;
        node* next;
        node() : data(T()), next(NULL) {
        }

        node(const T& data, node* next) : data(T(data), next(next)) {
        }
    };

protected:
    node* mFirst;
    size_t mSize;

public:
    list() : mFirst(NULL), mSize(0) {
    }
    ~list() {
        clear();
    }

}

int main() {
    node<int>* p = NULL;
    p = new node<int>(10, NULL);

    node<int>* q = NULL;
    q = new node<int>(20, NULL);

    p->next = p;
    q->next = node<int>(30, NULL);
}