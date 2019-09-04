#include <iostream>
using namespace std;
struct Node {
    int key, dep;
    Node *left, *right;
    Node (int k, int d) : key(k), dep(d), left(NULL), right(NULL) {  }
};
int max_dep = -1, gcnt1 = 0, gcnt2 = 0;
Node* insert(Node *root, int key, int dep) {
    if (root == NULL) {
        if (dep > max_dep) max_dep = dep;
        return new Node(key, dep);
    }
    if (key <= root->key) root->left = insert(root->left, key, dep + 1);
    else if (key > root->key) root->right = insert(root->right, key, dep + 1);
    return root;
}
void dfs(Node *root, int dep) {
    if (root == NULL) return;
    if (dep == max_dep) { gcnt2++; }
    if (dep == max_dep - 1) { gcnt1++; }
    dfs(root->left, dep + 1);
    dfs(root->right, dep + 1);
}
int main() {
    int n, t;
    Node* root = NULL;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> t;
        root = insert(root, t, 0);
    }
    dfs(root, 0);
    cout << gcnt2 << " + " << gcnt1 << " = " << gcnt1 + gcnt2 << "\n";
    return 0;
}

