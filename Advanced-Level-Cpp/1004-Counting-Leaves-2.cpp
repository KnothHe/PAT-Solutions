/*
 * bfs
 *
 */
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
const int maxn = 105;
vector<vector<int>> tree(maxn);
vector<int> cnts(maxn, 0);
int max_dep = -1;
int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int id, k, t;
        cin >> id >> k;
        for (int i = 0; i < k; i++) {
            cin >> t;
            tree[id].push_back(t);
        }
    }
    queue<vector<int>> que;
    que.push({1, 1});
    while (!que.empty()) {
        auto cur = que.front();
        que.pop();
        for (auto next : tree[cur[0]]) {
            que.push({next, cur[1] + 1});
        }
        if (tree[cur[0]].empty()) cnts[cur[1]]++;
        max_dep = cur[1];
    }
    for (int i = 1; i <= max_dep; i++) {
        if (i != 1) { cout << " "; }
        cout << cnts[i];
    }
    return 0;
}

