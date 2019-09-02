#include <iostream>
#include <vector>
using namespace std;
struct Node {
    int left, right;
};
vector<Node> nodes;
int n, root = 0, max_idx = -1, rs;
void dfs(int root, int idx) {
    if (idx > max_idx) {
        max_idx = idx;
        rs = root;
    }
    if (nodes[root].left != -1) dfs(nodes[root].left, idx * 2);
    if (nodes[root].right != -1) dfs(nodes[root].right, idx * 2 + 1);
}
int main() {
    cin >> n;
    nodes.resize(n);
    vector<bool> roots(n, true);
    for (int i = 0; i < n; i++) {
        string a, b;
        cin >> a >> b;
        if (a != "-") {
            nodes[i].left = stoi(a);
            roots[nodes[i].left] = false;
        } else { nodes[i].left = -1; }
        if (b != "-") {
            nodes[i].right = stoi(b);
            roots[nodes[i].right] = false;
        } else { nodes[i].right = -1; }
    }
    while (!roots[root]) { root++; }
    dfs(root, 1);
    if (max_idx == n) {
        cout << "YES " << rs;
    } else {
        cout << "NO " << root;
    }
    return 0;
}

