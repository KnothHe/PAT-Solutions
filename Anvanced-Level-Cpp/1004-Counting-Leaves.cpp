/*
 * dfs
 *
 */
#include <iostream>
#include <vector>
using namespace std;
const int maxn = 105;
vector<vector<int>> tree(maxn);
vector<int> cnts(maxn, 0);
int max_dep = -1;
void dfs(int cur, int depth) {
    if (tree[cur].empty()) {
        cnts[depth]++;
        if (depth > max_dep) {
            max_dep = depth;
        }
    }
    for (int next : tree[cur]) {
        dfs(next, depth + 1);
    }
}
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
    dfs(1, 1);
    for (int i = 1; i <= max_dep; i++) {
        if (i != 1) { cout << " "; }
        cout << cnts[i];
    }
    return 0;
}

