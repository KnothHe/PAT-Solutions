/*
 * After sorting input array, the sequence of this array is inorder.
 * Use this information to build the tree.
 *
 * After building the tree, just use bfs get levelorder.
 *
 */
#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
struct Node {
    int val, left, right;
};
vector<Node> nodes;
vector<int> in, level;
int idx = 0;
void inorder(int root) {
    if (root == -1) return;
    Node cur = nodes[root];
    inorder(cur.left);
    nodes[root].val = in[idx++];
    inorder(cur.right);
}
void bfs(int root) {
    queue<Node> que;
    que.push(nodes[root]);
    while (!que.empty()) {
        Node cur = que.front();
        que.pop();
        if (cur.left != -1) que.push(nodes[cur.left]);
        if (cur.right != -1) que.push(nodes[cur.right]);
        level.push_back(cur.val);
    }
}
int main() {
    int n;
    cin >> n;
    nodes.resize(n);
    in.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> nodes[i].left >> nodes[i].right;
    }
    for (int i = 0; i < n; i++) {
        cin >> in[i];
    }
    sort(in.begin(), in.end());
    inorder(0);
    bfs(0);
    if (!level.empty()) cout << level[0];
    for (int i = 1; i < level.size(); i++) { cout << " " << level[i]; }
    return 0;
}

