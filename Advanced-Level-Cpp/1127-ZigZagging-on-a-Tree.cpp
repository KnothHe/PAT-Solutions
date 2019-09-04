#include <iostream>
#include <vector>
#include <queue>
using namespace std;
struct Node {
    int val;
    Node *left, *right;
    Node (int v) : val(v), left(NULL), right(NULL) {  }
};
vector<int> in, post, zz;
Node *buildTree(Node *root, int postr, int inl, int inr) {
    if (inl > inr) return NULL;
    int idx;
    for (idx = inl; idx <= inr && in[idx] != post[postr]; idx++) {  }
    root = new Node(post[postr]);
    root->left = buildTree(root->left, postr-inr+idx-1, inl, idx-1);
    root->right = buildTree(root->right, postr-1, idx+1, inr);
    return root;
}
void zzorder(Node *root) {
    queue<pair<Node*, int>> que;
    que.push({root, 0});
    bool l2r = true;
    while (!que.empty()) {
        auto cur = que.front();
        vector<Node*> vec;
        while (!que.empty() && que.front().second == cur.second) {
            vec.push_back(que.front().first);
            if (vec.back()->left != NULL) que.push({vec.back()->left, cur.second+1});
            if (vec.back()->right != NULL) que.push({vec.back()->right, cur.second+1});
            que.pop();
        }
        if (l2r) {
            for (int i = vec.size()-1; i >= 0; i--) { zz.push_back(vec[i]->val); }
            l2r = false;
        } else {
            for (int i = 0; i < vec.size(); i++) { zz.push_back(vec[i]->val); }
            l2r = true;
        }
    }
}
int main() {
    int n;
    cin >> n;
    in.resize(n);
    post.resize(n);
    for (int i = 0; i < n; i++) { cin >> in[i]; }
    for (int i = 0; i < n; i++) { cin >> post[i]; }
    Node *root = NULL;
    root = buildTree(root, n-1, 0, n-1);
    zzorder(root);
    if (zz.size() > 0) { cout << zz[0]; }
    for (int i = 1; i < zz.size(); i++) { cout << " " << zz[i]; }
    return 0;
}

