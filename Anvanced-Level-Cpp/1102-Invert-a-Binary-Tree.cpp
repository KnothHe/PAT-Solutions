#include <iostream>
#include <vector>
#include <string>
#include <queue>
using namespace std;
struct Node {
    int left, right;
};
vector<Node> nodes;
vector<int> level, in;
void invert(int root) {
    if (root == -1) return;
    invert(nodes[root].left);
    invert(nodes[root].right);
    int left = nodes[root].left;
    nodes[root].left = nodes[root].right;
    nodes[root].right = left;
}
void levelorder(int root) {
    queue<int> que;
    que.push(root);
    while (!que.empty()) {
        int cur = que.front();
        que.pop();
        if (nodes[cur].left != -1) que.push(nodes[cur].left);
        if (nodes[cur].right != -1) que.push(nodes[cur].right);
        level.push_back(cur);
    }
}
void inorder(int root) {
    if (root == -1) return;
    inorder(nodes[root].left);
    in.push_back(root);
    inorder(nodes[root].right);
}
void print_vec(vector<int> &v) {
    if (!v.empty()) cout << v[0];
    for (int i = 1; i < v.size(); i++) { cout << " " << v[i]; }
    cout << "\n";
}
int main() {
    int n;
    cin >> n;
    nodes.resize(n);
    vector<bool>  roots(n, true);
    for (int i = 0; i < n; i++) {
        string left, right;
        cin >> left >> right;
        nodes[i].left = left == "-" ? -1 : stoi(left);
        nodes[i].right = right == "-" ? -1 : stoi(right);
        if (nodes[i].left != -1) roots[nodes[i].left] = false;
        if (nodes[i].right != -1) roots[nodes[i].right] = false;
    } 
    int root;
    for (int i = 0; i < roots.size(); i++) if (roots[i]) root = i;
    invert(root);
    levelorder(root);
    inorder(root);
    print_vec(level);
    print_vec(in);
    return 0;
}
