### TreeNode

```cpp
class node {
    public:
        ValueT data;
        node *left, *right, *parent;
        node():
            data(ValueT()), left(NULL), right(NULL), parent(NULL) {}
        node(const ValueT& data, node* left, node* right, node* parent):
            data(data), left(left), right(right), parent(parent) {}
}
```

---

### Huffman Coding

- ASII Code

  - Fix length encoding
  - Each char = 8 bits

- 16 different character Fix-length needs 4\*86 = 344 bits
- Variable Length need 327 bits

**Problem Statement**

- input: a string
- output: encoding of each character in the string such that
  1. the total length of encoding the string is mininmum
  2. the encoding of character is not ambiguous
  - Any character encoding is not a prefix of any other character

#### Tree Encoding

- using a `tree` to represent encoding
- Each charater is represent at `leaf nodes`
- Encode by start at the root and `walk toward leaft nodes`
  - the path gives the encoding
  - going to left child equal to 0
  - going to right child equal to 1
- Guarantee to be non-ambiguous

## Huffman Tree

- find 2 min nodes
- create a new node with thos two nodes as children, set freq equal to summation
- repeat until only one node left

### Recursive programming

- a function that call itself
- must have some input, usually via function argument
- the functino must check a condition for execution
  - result in either `termination case` where the function won't call itself
  - or `recursion case` where the function will call itself `with different parameters`

```cpp
int recur1(int n) {
    if (n <= 0) return 0;
    return recur1(n-1) + n;
}
```

**more example**

```cpp
void print_range1(int step, int goal) {
    if (step < goal) [
        std::cout << step << " ";
        print_range1(step+1, goal);
    ]
}

void print_range2(int step, int goal) {
    if (step < goal) {
        print_range2(step+1, goal);
        std::cout << step << " ";
    }
}
```

- print_range1(0,5) = '0 1 2 3 4'
- print_range2(0,5) = '4 3 2 1 0'

### Huffman Tree Node

```cpp
class huffman_tree {
    protected:
        class huffman_node {
            char letter;
            int freq;
            huffman_node *left, *right;
            huffman_node(): letter('*'), freq(0), left(NULL), right(NULL) {}
            huffman_node(char letter, int freq, huffman_node *left, huffman_node *right):
                letter(letter), freq(freq), left(left), right(right) {}
            bool is_leaf() {return left == NULL && right == NULL;}
        }
        huffman_node *root;
        void build_tree(vector<huffman_node*> data) {
            priority_queue<huffman_node*, vector<huffman_node*>, node_comparator> pq;
            for (auto &x : data) pq.push(x);
            while (pq.size() > 1) {
                huffman_node *right = pq.top(); pq.pop();
                huffman_node *left = pq.top(); pq.pop();
                pq.push(new huffman_node('*', left->freq + right->freq));
            }
            root = pq.top();
        }
    public:
        huffman_tree(string s) {
            map<char, int> count;
            for (auto &c : s)
                count[c]++;
            vector<huffman_node*> nodes;
            for (auto &x :count)
                nodes.push_back(new huffman_node(x.first, x.second, NULL, NULL));
            build_tree(nodes);
        }

    class node_comparator {
        public:
            // true when a coms before b
            bool operator()(const huffman_node *a, const huffman_node *b) {
                return a->freq > b->freq;
            }
    }
}
```

---

### Recursion on Binary Tree

**Tree Size by Recursion**

```cpp
class node {
    public:
        int data;
        node *left, *right;
}

int get_size(node* n) {
    if (n == NULL) return 0;
    return 1 + get_size(n->left) + get_size(n->right);
}

int get_height(node* n) {
    if (n == NULL) return -1;
    return 1 + std::max(get_height(n->left), get_height(n->right));
}
```

**Tree copy**

```cpp
node* copy(node* n) {
    if (n==NULL) retur NULL;
    node *lc = copy(n->left);
    node *rc = copy(n->right);
    node *result = new node(n->data, lc, rc);
}
```

#### Walk over a tree

- visiting all nodes

- preorder traversal

```cpp
void preorder(node* n) {
    if (n == NULL) return;
    std::cout << n->data << " ";
    preorder(n->left);
    preorder(n->right);
}
```

- inorder traversal

```cpp
void inorder(node* n) {
    if (n == NULL) return;
    std::cout << n->data << " ";
    inorder(n->left);
    inorder(n->right);
}
```

- postorder traversal

```cpp
void postorder(node* n) {
    if (n == NULL) return;
    postorder(n->left);
    postorder(n->right);
    std::cout << n->data << " ";
}
```

### Huffman Tree: Encoding

```cpp
class huffman_tree {
    protected:
        class huffman_node {...};
        class node_comparator {...};
        huffman_node *root;
    public:
        void print(huffman_node *n, string s) {
            if (n->is_leaf()) {
                cout << n->letter << ": " << s << "\n";
            } else {
                print(n->left, s+"0");
                print(n->right, s+"1");
            }
        }
        ~huffman_tree() {
            delete_node(root);
        }

        void print() {
            print(root, "");
        }

        void delete_node(huffman_node *n) {
            if (n==NULL) return;
            delete_node(n->left);
            delete_node(n->right);
            delete n;
        }
}
```
