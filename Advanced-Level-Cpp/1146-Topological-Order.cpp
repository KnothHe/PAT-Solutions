#include <iostream>
#include <vector>
#include <set>
using namespace std;
const int maxn = 1005;
vector<vector<int>> gp(maxn);
bool is_tod, mark[maxn];
set<int> inset;
void dfs(int cur) {
    if (inset.find(cur) != inset.end()) {
        is_tod = false;
        return;
    }
    for (int next : gp[cur]) {
        if (!mark[next]) {
            mark[next] = true;
            dfs(next);
        }
    }
}
int main() {
    int n, m, u, v, k;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        cin >> u >> v;
        gp[u].push_back(v);
    }
    cin >> k;
    vector<int> tod(n), rs;
    for (int i = 0; i < k; i++) {
        for (int j = 0; j < n; j++) {
            cin >> tod[j];
        }
        inset.clear();
        is_tod = true;
        for (int j = 0; j < n; j++) {
            if (is_tod) {
                fill(mark, mark + maxn, false);
                dfs(tod[j]);
            }
            inset.insert(tod[j]);
        }
        if (!is_tod) rs.push_back(i);
    }
    for (int i = 0; i < rs.size(); i++) {
        if (i != 0) { cout << " "; }
        cout << rs[i];
    }
    return 0;
}

