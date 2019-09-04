#include <iostream>
#include <vector>
using namespace std;
struct Node {
    int val;
    bool red;
    Node *left, *right;
    Node(int v) : val(abs(v)), red(v < 0), left(NULL), right(NULL) {  }
};
Node *insert(Node *root, int val) {
    if (root == NULL) { return new Node(val); }
    else if (abs(val) < root->val) {
        root->left = insert(root->left, val);
    } else {
        root->right = insert(root->right, val);
    }
    return root;
}
bool check1(Node *root) {
    if (root == NULL) { return true; }
    if (root->red) {
        if (root->left != NULL && root->left->red) { 
            return false;
        }
        if (root->right != NULL && root->right->red) { 
            return false;
        }
    }
    return check1(root->left) && check1(root->right);
}
int getLevel(Node *root) {
    if (root == NULL) return 1;
    int l = getLevel(root->left);
    int r = getLevel(root->right);
    return root->red ? max(l, r) : max(l, r) + 1;
}
bool check2(Node *root) {
    if (root == NULL) { return true; }
    int l = getLevel(root->left);
    int r = getLevel(root->right);
    if (l != r) { return false; };
    return check2(root->left) && check2(root->right);
}
int main() {
    int k, n, v;
    cin >> k;
    for (int i = 0; i < k; i++) {
        cin >> n;
        Node *root = NULL;
        for (int j = 0; j < n; j++) {
            cin >> v;
            root = insert(root, v);
        }
        if (root->red || !check1(root) || !check2(root)) {
            cout << "No\n";
        } else {
            cout << "Yes\n";
        }
    }
    return 0;
}

