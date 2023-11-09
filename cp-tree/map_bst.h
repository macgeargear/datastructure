#ifndef _MAP_BST_
#define _MAP_BST_
#include <iostream>

template <typename KeyT, typename MappedT, typename CompareT = std::less<KeyT>>
class map_bst {
protected:
    typedef std::pair<KeyT, MappedT> ValueT;
    class node {
        friend class map_bst;

    protected:
        ValueT data;
        node* left;
        node* right;
        node* parent;
        node() : data(ValueT()), left(NULL), right(NULL), parent(NULL) {
        }
        node(const ValueT& data, node* left, node* right, node* parent)
            : data(data), left(left), right(right), parent(parent) {
        }
    };

    // tree_iterator
    class tree_iterator {
    protected:
        node* ptr;

    public:
        tree_iterator() : ptr(NULL) {
        }
        tree_iterator(node* a) : ptr(a) {
        }

        tree_iterator& operator++() {
        }

        tree_iterator& operator--() {
        }

        tree_iterator operator++() {
        }

        tree_iterator operator--() {
        }

        ValueT& operator*() {
            return ptr->data;
        }

        ValueT* operator->() {
            return &(ptr->data);
        }

        bool operator==(const tree_iterator& other) {
        }
        bool operator!=(const tree_iterator& other) {
        }
    };

    node* mRoot;
    CompareT mLess;
    size_t mSize;

public:
    typedef tree_iterator iterator;

protected:
}

#endif