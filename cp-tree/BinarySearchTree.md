# Binary Search Tree

**overview**

- we add additional `value constraint` to a Binary Tree
- The constraint make finding data in the tree much faster
  - `O(h)`: h is height of the tree
- using the same approach as a binary heap, maintain the constraint during modification

**Constraint**

- data in `left-subtree` must be `lass than` the data in x
- data in `right-subtree` must be `more than` the data in x

- Recursive Definition
  - An `empty tree` is a BST
  - A node `X` is a BST when
    1. its subtrees (if any) must be BST and
    2. if `left-subtree` exist, `X->data` must be more than `X->left->data`
    3. if `right-subtree` exist, `X->data` must be more than `X->right->data`

### Finding Value in BST

- to find `e` start from root
  - if the current node is not `e`
    - search in left-subtree if `e` `less` then then `current node`
  - keep going until we find `e` or reach `NULL`
- other operation also depends on find

```cpp
node* find_node(const ValueT& k, node* r, node* &parent) {
    node *ptr = r;
    while (ptr != null) {
        int cmp = compare(k, ptr->data); // -1: a<b, 0: a==b, 1: a>b
        if (cmp == 0) return ptr;
        parent = ptr;
        ptr = cmp < 0 ? ptr->left : ptr->right;
    }
    return NULL;
}
```

### Insert

- Assumption: Data in BST is unique
- `insert(e)` by find e
  - if `e` is found, don't add any node
  - if `e` is not in BST, find must reach `NULL` somewhere, that `NULL` is where to put `e`
- both structure and value constraints are satisfied

### Erase

- `erase(e)` first have to find `e` as well
- if not found, do nothing
- if found at node `X`, there are `3 cases`
  - if has `no child`: just simply delete `X`
  - if has `one child`, have parent of X `points` (using the same link) `to the child of X` instead
  - if has `two children`, pick either `successor` or `predecessor` of `e`
    - assume we choose `successor p` (must be in right-subtree), replace `X` with `P` and `erase(p)` from right-subtree

#### Erase node with 2 childrens

- Replace by `succesor` (or `predecessor`) preserves value rules
  - `Successor` is the minimum in `right subtree`
  - `Predecessor` is the maximum in `left subtree`
- Both exists (becasue the node has both subtrees)

#### Finding Successor and Predcessor

- `Successor` is the minimum in `right subtree`
- if a tree has `left-subtree`, min is the min of `left-subtree`
  - if not, min is the root

```cpp
node* find_min_node(node* r) {
    // r must not be NULL
    node *min = r;
    while (min->left != NULL) {
        min = min->left;
    }
    return min
}
// recursive ver.
node* find_min_node(node* r) {
    if (r->left == NULL) return r;
    return find_min_node(r->left);
}
```

- `Predecessor` is the maximum in `left subtree`
- if a tree has `right-subtree`, max is the max of `right-subtree`
  - if not, max is the root

```cpp
node* find_max_node(node* r) {
    // r must not be NULL
    node *max = r;
    while (max->right != NULL) {
        max = max->right;
    }
    return max;
}
// vercursive ver.
node* find_max_node(node* r) {
    if (r->right == NULL) return r;
    return find_max_node(r->right);
}
```

**Complexity Analysis**

- insert, erase depends on `find`
- height can be in the range from `n` to `log(n)`
- for 1,000,000 nodes, its in the range of [20, 999,999]
  - `O(h) is now O(n)`
  - will be fixed by `AVL` tree
