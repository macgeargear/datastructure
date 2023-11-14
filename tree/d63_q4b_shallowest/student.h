#ifndef __STUDENT_H_
#define __STUDENT_H_

#include <algorithm>
#include <iostream>

#include "map_bst.h"

// you can use this function
template <typename KeyT, typename MappedT, typename CompareT>
int CP::map_bst<KeyT, MappedT, CompareT>::shallowest_leaf(node* n) {
    if (!n)
        return -1;
    int left = shallowest_leaf(n->left);
    int right = shallowest_leaf(n->right);
    if (left == right && left == -1)
        return 0;
    if (left == -1)
        return 1 + right;
    if (right == -1)
        return 1 + left;

    return 1 + std::min(left, right);
}

template <typename KeyT, typename MappedT, typename CompareT>
int CP::map_bst<KeyT, MappedT, CompareT>::shallowest_leaf() {
    // write your code here
    return shallowest_leaf(mRoot);
}

#endif
