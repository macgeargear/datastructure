#ifndef __STUDENT_H_
#define __STUDENT_H_

#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

// you can modify and use this function
template <typename KeyT, typename MappedT, typename CompareT>
void CP::map_bst<KeyT, MappedT, CompareT>::my_recur(node* n, size_t level,
                                                    size_t tmp,
                                                    std::vector<KeyT>& v) {
    // you MAY need to use this function
}

template <typename KeyT, typename MappedT, typename CompareT>
std::vector<KeyT> CP::map_bst<KeyT, MappedT, CompareT>::at_level(size_t level) {
    // write your code here
    std::queue<node*> q;
    std::vector<std::vector<KeyT>> v;
    q.push(mRoot);
    while (!q.empty()) {
        int n = q.size();
        std::vector<KeyT> curr;
        for (int i = 0; i < n; i++) {
            node* currNode = q.front();
            q.pop();  //
            curr.push_back(currNode->data.first);
            if (currNode->left)
                q.push(currNode->left);
            if (currNode->right)
                q.push(currNode->right);
        }
        sort(curr.begin(), curr.end(), std::greater<KeyT>());
        v.push_back(curr);
        if (v.size() > level)
            break;
    }
    return v[level];
}

#endif
