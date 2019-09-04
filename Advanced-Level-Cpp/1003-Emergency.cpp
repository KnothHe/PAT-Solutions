/*
 * dfs
 *
 */
#include <iostream>
#include <vector>
using namespace std;
const int maxn = 505, pinf = 99999999;
vector<vector<int>> gp(maxn, vector<int>(maxn, -1));
vector<int> num(maxn, 0), diffr(maxn, 0), amo(maxn, 0), dist(maxn, pinf);
vector<bool> mark(maxn, false);
int main() {
    int n, m, c1, c2;
    cin >> n >> m >> c1 >> c2;
    for (int i = 0; i < n; i++) { cin >> num[i]; }
    for (int i = 0; i < m; i++) {
        int u, v, l;
        cin >> u >> v >> l;
        gp[u][v] = gp[v][u] = l;
    }
    diffr[c1] = 1;
    amo[c1] = num[c1];
    dist[c1] = 0;
    while (true) {
        int cur = -1, min_dist = pinf;
        for (int i = 0; i < n; i++) {
            if (!mark[i] && dist[i] < min_dist) {
                cur = i;
                min_dist = dist[i];
            }
        }
        if (cur == -1) { break; }
        mark[cur] = true;
        for (int i = 0; i < n; i++) {
            if (!mark[i] && gp[cur][i] != -1) {
                if (dist[cur] + gp[cur][i] < dist[i]) {
                    dist[i] = dist[cur] + gp[cur][i];
                    amo[i] = amo[cur] + num[i];
                    diffr[i] = diffr[cur];
                } else if (dist[cur] + gp[cur][i] == dist[i]) {
                    diffr[i] = diffr[cur] + diffr[i];
                    if (amo[cur] + num[i] > amo[i]) {
                        amo[i] = amo[cur] + num[i];
                    }
                }
            }
        }
    }
    cout << diffr[c2] << " " << amo[c2] << "\n";
    return 0;
}

