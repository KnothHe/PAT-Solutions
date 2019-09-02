/*
 * Reference:
 *  https://www.liuchuo.net/archives/2178
 *
 * Handwritten AVL tree construction......
 *
 */
#include <algorithm>
#include <iostream>
using namespace std;
struct Node {
    int val;
    Node *left, *right;
    Node(int v) : val(v), left(NULL), right(NULL) {  }
};
int getHeight(Node* root) {
    if (root == NULL) return 0;
    return max(getHeight(root->left), getHeight(root->right)) + 1;
}
Node* rotateLeft(Node* root) {
    Node *t = root->right;
    root->right = t->left;
    t->left = root;
    return t;
}
Node* rotateRight(Node* root) {
    Node *t = root->left;
    root->left = t->right;
    t->right = root;
    return t;
}
Node* rotateLeftRight(Node* root) {
    root->left = rotateLeft(root->left);
    return rotateRight(root);
}
Node* rotateRightLeft(Node* root) {
    root->right = rotateRight(root->right);
    return rotateLeft(root);
}
Node* insert(int val, Node* root) {
    if (root == NULL) root = new Node(val);
    else if (val < root->val) {
        root->left = insert(val, root->left);
        if (getHeight(root->left) - getHeight(root->right) == 2)
            root = val < root->left->val ? rotateRight(root) : rotateLeftRight(root);
    } else {
        root->right = insert(val, root->right);
        if (getHeight(root->left) - getHeight(root->right) == -2)
            root = val > root->right->val ? rotateLeft(root) : rotateRightLeft(root);
    }
    return root;
}
int main() {
    int n, val;
    cin >> n;
    Node* root = NULL;
    for (int i = 0; i < n; i++) {
        cin >> val;
        root = insert(val, root);
    }
    cout << root->val;
    return 0;
}

