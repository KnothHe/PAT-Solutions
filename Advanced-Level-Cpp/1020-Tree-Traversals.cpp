#include <iostream>
#include <vector>
#include <queue>
using namespace std;
struct Node {
    int n;
    Node* left;
    Node* right;
    Node(int num) : n(num), left(NULL), right(NULL) {  }
};
Node* root;
const int MAX_N = 35;
vector<int> postorder(MAX_N);
vector<int> inorder(MAX_N);
int N;
vector<int> levelorder;
void buildTree(Node* &node, int pb, int pe, int ib, int ie) {
    if (pb > pe || ib > ie) {
        return;
    }
    node = new Node(postorder[pe]);
    int index;
    for (index = ib; index <= ie; index++) {
        if (inorder[index] == node->n) {
            break;
        }
    }
    buildTree(node->left, pb, pe - (ie - index) - 1, ib, index - 1);
    buildTree(node->right, pe - (ie - index), pe - 1, index + 1, ie);
}
void bfs(Node* root) {
    queue<Node*> que;
    que.push(root);
    while (!que.empty()) {
        Node* node = que.front(); que.pop();
        levelorder.push_back(node->n);
        if (node->left != NULL) {
            que.push(node->left);
        }
        if (node->right != NULL) {
            que.push(node->right);
        }
    }
}
int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> postorder[i];
    }
    for (int i = 0; i < N; i++) {
        cin >> inorder[i];
    }
    buildTree(root, 0, N - 1, 0, N - 1);
    bfs(root);
    for (int i = 0; i < levelorder.size(); i++) {
        if (i != 0) {
            cout << " ";
        }
        cout << levelorder[i];
    }
    cout << endl;
    return 0;
}

