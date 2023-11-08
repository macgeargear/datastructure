class huffman_tree {
protected:
    class huffman_node {
        char letter;
        int freq;
        huffman_node *left, *right;
        huffman_node() : letter('*'), freq(0), left(NULL), right(NULL) {
        }
        huffman_node(char letter, int freq, huffman_node *left,
                     huffman_node *right)
            : letter(letter), freq(freq), left(left), right(right) {
        }
        bool is_leaf() {
            return left == NULL && right == NULL;
        }
    } class node_comparator {
    public:
        // true when a coms before b
        bool operator()(const huffman_node *a, const huffman_node *b) {
            return a->freq > b->freq;
        }
    }
}