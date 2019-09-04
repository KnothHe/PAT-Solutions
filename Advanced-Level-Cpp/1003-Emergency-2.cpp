/*
 * Dijkstra
 *
 */
#include <iostream>
#include <vector>
using namespace std;
const int maxn = 505;
vector<int> amo(maxn);
vector<bool> mark(maxn, false);
vector<vector<int>> gp(maxn, vector<int>(maxn, -1));
int n, m, c1, c2, glen = -1, gnum, gamo;
void dfs(int cur, int tlen, int tamo) {
    if (cur == c2) {
        if (glen == -1 || tlen < glen) {
            glen = tlen;
            gnum = 1;
            gamo = tamo;
        } else if (tlen == glen) {
            gnum++;
            if (tamo > gamo) {
                gamo = tamo;
            }
        }
        return;
    }
    for (int i = 0; i < maxn; i++) {
        if (!mark[i] && gp[cur][i] != -1) {
            mark[i] = true;
            dfs(i, tlen + gp[cur][i], tamo + amo[i]);
            mark[i] = false;
        }
    }
}
int main() {
    cin >> n >> m >> c1 >> c2;
    for (int i = 0; i < n; i++) { cin >> amo[i]; }
    for (int i = 0; i < m; i++) {
        int u, v, l;
        cin >> u >> v >> l;
        gp[u][v] = gp[v][u] = l;
    }
    mark[c1] = true;
    dfs(c1, 0, amo[c1]);
    cout << gnum << " " << gamo << "\n";
    return 0;
}

