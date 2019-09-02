/*
 * Reference: https://www.liuchuo.net/archives/3758
 *
 * Simular solution.
 *
 */
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
vector<int> in, post, rs[35];
int n, tree[35][2], root;
struct Node {
    int index, depth;
};
void dfs(int &index, int inl, int inr, int postr) {
    if (inl > inr) return;
    index = postr;
    int i = inl;
    while (i <= inr && in[i] != post[postr]) i++;
    dfs(tree[index][0], inl, i-1, postr-inr+i-1);
    dfs(tree[index][1], i+1, inr, postr-1);
}
void bfs() {
    queue<Node> que;
    que.push(Node{root, 0});
    while (!que.empty()) {
        Node t = que.front();
        que.pop();
        rs[t.depth].push_back(post[t.index]);
        if (tree[t.index][0] != 0) que.push({ tree[t.index][0], t.depth+1 });
        if (tree[t.index][1] != 0) que.push({ tree[t.index][1], t.depth+1 });
    }
}
int main() {
    cin >> n;
    in.resize(n+1);
    post.resize(n+1);
    for (int i = 1; i <= n; i++) { cin >> in[i]; }
    for (int i = 1; i <= n; i++) { cin >> post[i]; }
    dfs(root, 1, n, n);
    bfs();
    printf("%d", rs[0][0]);
    for (int i = 1; i < 35; i++) {
        if (i % 2 == 1) {
            for (int j = 0; j < rs[i].size(); j++) {
                cout << " " << rs[i][j];
            }
        } else {
            for (int j = rs[i].size() - 1; j >= 0; j--) {
                cout << " " << rs[i][j];
            }
        }
    }
    return 0;
}

