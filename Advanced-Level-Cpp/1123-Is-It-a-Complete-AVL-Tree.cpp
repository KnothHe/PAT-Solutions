#include <iostream>
#include <vector>
#include <queue>
using namespace std;
struct Node {
    int val;
    Node *left, *right;
    Node(int v) : val(v), left(NULL), right(NULL) {  }
};
vector<int> level;
int max_idx = -1;
int getHeight(Node* root) {
    if (root == NULL) return 0;
    return max(getHeight(root->left), getHeight(root->right)) + 1;
}
Node *rotateLeft(Node *root) {
    Node *t = root->right;
    root->right = t->left;
    t->left = root;
    return t;
}
Node *rotateRight(Node *root) {
    Node *t = root->left;
    root->left = t->right;
    t->right = root;
    return t;
}
Node *rotateRightLeft(Node *root) {
    root->right = rotateRight(root->right);
    return rotateLeft(root);
}
Node *rotateLeftRight(Node *root) {
    root->left = rotateLeft(root->left);
    return rotateRight(root);
}
Node *insert(Node *root, int val) {
    if (root == NULL) root = new Node(val);
    else if (val <= root->val) {
        root->left = insert(root->left, val);
        if (getHeight(root->left) - getHeight(root->right) == 2)
            root = val < root->left->val ? rotateRight(root) : rotateLeftRight(root);
    } else {
        root->right = insert(root->right, val);
        if (getHeight(root->right) - getHeight(root->left) == 2)
            root = val > root->right->val ? rotateLeft(root) : rotateRightLeft(root);
    }
    return root;
}
void levelorder(Node *root) {
    queue<Node*> que;
    que.push(root);
    while (!que.empty()) {
        Node* cur = que.front();
        que.pop();
        if (cur->left != NULL) que.push(cur->left);
        if (cur->right != NULL) que.push(cur->right);
        level.push_back(cur->val);
    }
}
void dfs(Node *root, int idx) {
    if (idx > max_idx) max_idx = idx;
    if (root->left != NULL) dfs(root->left, 2 * idx);
    if (root->right != NULL) dfs(root->right, 2 * idx + 1);
}
int main() {
    int n, t;
    cin >> n;
    Node *root = NULL;
    for (int i = 0; i < n; i++) {
        cin >> t;
        root = insert(root, t);
    }
    levelorder(root);
    dfs(root, 1);
    if (!level.empty()) cout << level[0];
    for (int i = 1; i < level.size(); i++) { cout << " " << level[i]; }
    if (max_idx == n) { cout << "\nYES\n"; }
    else { cout << "\nNO\n"; }
    return 0;
}

