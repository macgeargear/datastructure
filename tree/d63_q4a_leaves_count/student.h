#ifndef __STUDENT_H_
#define __STUDENT_H_

#include <algorithm>
#include <iostream>

#include "map_bst.h"

// you can modify and use this function
int cnt = 0;
template <typename KeyT, typename MappedT, typename CompareT>
size_t CP::map_bst<KeyT, MappedT, CompareT>::leaves_count(node* n) {
    if (n == NULL)
        return 0;
    if (n->left == NULL && n->right == NULL)
        return 1;
    return leaves_count(n->left) + leaves_count(n->right);
}

template <typename KeyT, typename MappedT, typename CompareT>
size_t CP::map_bst<KeyT, MappedT, CompareT>::leaves_count() {
    return leaves_count(mRoot);
    // write your code here
}

#endif
