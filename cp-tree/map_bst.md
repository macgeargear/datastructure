# CP::map_bst

**Layout**

- need node class
- also need iterator class
- template has two types
  - key type and mapped type
  - value type is `pair<KeyType, MappedType>`
- also need custom comparator

```cpp
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
        };
        class tree_iterator {
            protected:
                node* ptr;
            public:
        };
        node* mRoot;
        CompareT mLess;
        size_t mSize;
    public:
        typedef tree_iterator iterator;
}
```

**node class**

```cpp
class node {
    friend class map_bst;
    protected:
        ValueT data;
        node* left;
        node* right;
        node* parent;
};
```

**Ctors, Dtors**

```cpp
map_bst(const map_bst<KeyT, MappedT, CompareT>& other):
    mLess(other.mLess), mSize(other.mSize) {
        mRoot = copy(other.mRoot, NULL);
    }
map_bst(const CompareT& c = CompareT()): mRoot(NULL), mLess(c), mSize(0) {}
map_bst<KeyT, MappedT, CompareT>& operator=(map_bst<KeyT, MappedT, CompareT> other) {
    using std::swap;
    swap(this->mRoot, other.mRoot);
    swap(this->mLess, other.mLess);
    swap(this->mSize, other.mSize);
    return *this;
}
~msp_bst() {
    clear();
}
```

### Actual Find

- Find by Key

```cpp
int comnpare(const KeyT& k1, const KeyT& k2) {
    if (mLess(k1, k2)) return -1;
    if (mLess(k2, k1)) return +1;
    return 0;
}

node* find_node(const KeyT& k, node* r, node* &parent) {
    node *ptr = r;
    while (ptr != NULL) {
        int cmp = compare(k, ptr->data.first);
        if (cmp == 0) return ptr;
        parent = ptr;
        ptr = cmp < 0 ? ptr->left : ptr->right;
    }
    return NULL;
}

iterator find(const KeyT& key) {
    node *parent;
    node *ptr = find_node(key, mRoot, parent);
    return ptr = NULL ? end() : iterator(ptr);
}
```

### Insert

- insert return pair or iterator and insert result

```cpp
std::pair<iterator, bool> insert(const ValueT& val) {
    node *parent = NULL;
    node *ptr = find_node(val.first, mREoot, parent);
    bool not_found = (ptr == NULL);
    if (not_found) {
        ptr = new node(val, NULL, NULL, parent);
        child_link(parent, val.first) = ptr;
        mSize++;
    }
    return std::make_pair(iterator(ptr), not_found);
}

node* &child_link(node* parent, const KeyT& k) {
    if (parent == NULL) return mRoot;
    return mLess(k, parent->data.first) ? parent->left : parent->right;
}
```

### Erase

```cpp
size_t erase(const KeyT& &key) {
    if (mRoot == NULL) return 0;
    node *parent = NULL;
    node *ptr = find_node(key, mRoot, parent);
    if (ptr == NULL) return 0;
    if (ptr->left != NULL && ptr->right) {
        // delete min
        node *min = find_min_node(ptr->right);
        node* &link = child_link(min->parent, min->data.first);
        link = (ptr->left == NULL) ? ptr->right : ptr->left;
        if (link != NULL) link->parent = min->parent;
        std::swap(ptr->data.first, min->data.first);
        std::swap(ptr->data.second, min->data.second);
        ptr = min;
    } else {
        // have 1 child
        // delete ptr
        node* &link = child_link(ptr->parent, key);
        link = (ptr->left == NULL) ? ptr->right : ptr->left;
        if (link != NULL) return link->parent = ptr->parent;
    }
    delete ptr;
    mSize--;
    return 1;
}
```

#### Operator[]

- find node
- if not exists, create one with default MappedTypeReturn MappedType of the node

```cpp
MappedT& operator[](const KeyT& key) {
    node *parent = NULL;
    node *ptr = find_node(key, mRoot, parent);
    if (ptr == NULL) {
        ptr = new node(std::make_pair(key, MappedT()), NULL, NULL, parent);
        child_link(parent, key) = ptr;
        mSize++;
    }
    return ptr->data.second;
}
```

### Iterator

**Operator++**

- find `successor` of `x`, easy if `x` have `right-subtree`
  - just find `min` of `right-subtree`
- if not, we have to go up (go toward root) until we find one that is `more` than `x`
  - this is always the cloest `ancestor` of `x` that has `x` in its `left-subtree`

```cp

```

**Operator--**

- change min->max left->right from **Operator++**

```cpp
class tree_iterator {
    protected:
        node* ptr;
    public:
        tree_iterator(): ptr(NULL) {}
        tree_iterator(node* a): ptr(a) {}

        tree_iterator operator++(int) {
            tree_iterator tmp(*this);
            operator++();
            return tmp;
        }

        tree_iterator operator--(int) {
            tree_iterator tmp(*this);
            operator--();
            return tmp;
        }

        ValueT& operator*() { return ptr->data; }
        ValueT* operator->() {return &(ptr->data);}
        bool operator==(const tree_iterator& other)
            return other.ptr == ptr;
        bool operator!=(const tree_iterator& other)
            return other.ptr != ptr;
}
```

## Summary

- Binary Search Tree relies on `Value Constraint` to make find fast
  - Possible to be slow (will be fixed later)
- erase rquires `find_min, max`
- `CP::map_bst` use pair to store `KeyT` and `MappedT`
  - find use key
- `iterator` is just a pointer
  - have a problem of `operator--` at `end()` (will be fixed later)
