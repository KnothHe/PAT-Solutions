/*
 * dfs with level
 */
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
struct Node {
    int id, lev;
};
int n, l, m, k, t;
vector<vector<int>> gp;
int bfs(Node nd) {
    int fwd = 0;
    queue<Node> que;    
    vector<bool> mark(n + 1, false);
    que.push(nd);
    mark[nd.id] = true;
    while (!que.empty()) {
        Node cur = que.front();
        que.pop();
        for (auto next : gp[cur.id]) {
            if (!mark[next] && cur.lev < l) {
                que.push({ next, cur.lev + 1 });
                mark[next] = true;
                fwd++;
            }
        }
    }
    return fwd;
}
int main() {
    cin >> n >> l;
    gp.resize(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> m;
        for (int j = 0; j < m; j++) {
            cin >> t;
            gp[t].push_back(i);
        }
    }
    cin >> k;
    for (int i = 0; i < k; i++) {
        cin >> t;
        cout << bfs({ t, 0 }) << "\n";
    }
    return 0;
}

