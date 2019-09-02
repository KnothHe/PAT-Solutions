/*
 * Stupid solution, but AC.
 *
 * First, build the tree, then postorder travel the tree.
 *
 * When build the tree, every time push t, if cur->left is NULL, put t to cur's left,
 * else put t to cur's right. every time pop t, find point to the t in the tree.
 *
 */
#include <iostream>
#include <string>
#include <vector>
#include <stack>
using namespace std;
struct Node {
    int id;
    Node *left, *right;
    Node (int d) : id(d), left(NULL), right(NULL) {  }
};
vector<int> rs;
void postorder(Node *root) {
    if (root == NULL) return;
    postorder(root->left);
    postorder(root->right);
    rs.push_back(root->id);
}
Node* find(Node *root, int id) {
    if (root->id == id) return root;
    if (root->right != NULL) return find(root->right, id);
    if (root->left != NULL) return find(root->left, id);
    return NULL;
}
int main() {
    int n, t;
    string op;
    stack<int> st;
    cin >> n;
    Node *root = NULL, *cur = NULL;
    bool pop_left = true;
    for (int i = 1; i <= 2*n; i++) {
        cin >> op;
        switch (op[1]) {
            case 'u' :
                cin >> t;
                st.push(t);
                if (root == NULL) {
                    root = new Node(t);
                    cur = root;
                } else {
                    if (cur->left == NULL) {
                        cur->left = new Node(t);
                        cur = cur->left;
                    } else {
                        cur->right = new Node(t);
                        cur = cur->right;
                    }
                }
                break;
            case 'o' :
                t = st.top();
                st.pop();
                cur = find(root, t);
                break;
        }
    }
    postorder(root);
    if (!rs.empty()) cout << rs[0];
    for (int i = 1; i < rs.size(); i++) { cout << " " << rs[i]; }
    return 0;
}

