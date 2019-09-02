/*
 * bfs with level.
 */
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
struct Node {
    int id, lev;
};
vector<vector<int>> gp;
vector<int> levs;
void bfs(int root) {
    queue<Node> que;
    que.push({root, 1});
    levs.push_back(0);
    while (!que.empty()) {
        Node cur = que.front();
        que.pop();
        for (int next : gp[cur.id]) {
            que.push({next, cur.lev + 1});
        }
        levs[cur.lev]++;
    }
}
int main() {
    int n, m, t, tn, tt;
    cin >> n >> m;
    gp.resize(n + 1);
    levs.resize(n + 1, 0);
    for (int i = 0; i < m; i++) {
        cin >> t >> tn;
        for (int j = 0; j < tn; j++) {
            cin >> tt;
            gp[t].push_back(tt);
        }
    }
    bfs(1);
    int max_lev = -1, max_idx;
    for (int i = 0; i < levs.size(); i++) {
        if (levs[i] > max_lev) {
            max_idx = i;
            max_lev = levs[i];
        }
    }
    cout << max_lev << " " << max_idx;
    return 0;
}

