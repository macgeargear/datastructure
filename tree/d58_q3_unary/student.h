#ifndef __STUDENT_H__
#define __STUDENT_H__

#include "map_bst.h"

template <typename KeyT, typename MappedT, typename CompareT>
size_t CP::map_bst<KeyT, MappedT, CompareT>::process(node* ptr) const {
    // you may write additional code here
    if (ptr == NULL)
        return -1;
    if (!ptr->left && !ptr->right)
        return 0;
    if (!ptr->left && ptr->right)
        return 1 + process(ptr->right);
    if (!ptr->right && ptr->left) {
        return 1 + process(ptr->left);
    }
    return process(ptr->left) + process(ptr->right);
}

template <typename KeyT, typename MappedT, typename CompareT>
size_t CP::map_bst<KeyT, MappedT, CompareT>::count_unary() const {
    // write your code here
    return process(mRoot);
}

#endif
