#ifndef __STUDENT_H__
#define __STUDENT_H__

#include <algorithm>
#include <vector>

#include "map_bst.h"

template <typename KeyT, typename MappedT, typename CompareT>
size_t CP::map_bst<KeyT, MappedT, CompareT>::process(node *n) {
    // write your code here
    if (!n)
        return 0;
    return 1 + process(n->left) + process(n->right);
}

template <typename KeyT, typename MappedT, typename CompareT>
std::pair<KeyT, MappedT> CP::map_bst<KeyT, MappedT, CompareT>::subtree(
    map_bst<KeyT, MappedT, CompareT> &left,
    map_bst<KeyT, MappedT, CompareT> &right) {
    if (mRoot == NULL)
        return std::pair<KeyT, MappedT>();
    size_t l = process(mRoot->left);
    size_t r = process(mRoot->right);
    if (mRoot->left) {
        left.clear();
        left.mSize = l;
        left.mRoot = mRoot->left;
    }

    if (mRoot->right) {
        right.clear();
        right.mSize = r;
        right.mRoot = mRoot->right;
    }
    // left(mRoot->left);
    // right(mRoot->right);
    // write your code here
    mRoot->left = NULL;
    mRoot->right = NULL;
    mSize = 1;
    return mRoot->data;
}

#endif
