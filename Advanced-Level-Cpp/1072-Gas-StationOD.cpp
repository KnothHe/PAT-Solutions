/*
 * Reference:
 *  https://brickmaker.github.io/2018/08/24/PAT-A-1072/
 *
 * Dijkstra
 *
 */
#include <iostream>
#include <string>
#include <vector>
#include <climits>
#include <cstdio>
using namespace std;
int getIndex(string p, int n) {
    int rs;
    if (p[0] == 'G') { rs = n + stoi(p.substr(1)); }
    else { rs = stoi(p); }
    return rs;
}
int main() {
    int n, m, k, ds, dist;
    cin >> n >> m >> k >> ds;
    string p1, p2;
    vector<vector<int>> graph(n + m + 1, vector<int>(n + m + 1, INT_MAX));
    for (int i = 0; i < k; i++) {
        cin >> p1 >> p2 >> dist;
        int g1 = getIndex(p1, n), g2 = getIndex(p2, n);
        graph[g1][g2] = graph[g2][g1] = dist;
    }
    int fp = -1;
    double fminds = 1.0 * INT_MIN, favg = 1.0 * INT_MAX;
    for (int i = n + 1; i <= n + m; i++) {
        vector<int> dists(n + m + 1, INT_MAX);
        vector<bool> mark(n + m + 1, false);
        dists[i] = 0;
        for (int j = 1; j <= n + m; j++) {
            int cur = -1, minds = INT_MAX;
            for (int k = 1; k <= n + m; k++) {
                if (!mark[k] && dists[k] < minds) {
                    cur = k;
                    minds = dists[k];
                }
            }
            if (cur == -1) break;
            mark[cur] = true;
            for (int k = 1; k <= n + m; k++) {
                if (graph[cur][k] != INT_MAX && dists[cur] + graph[cur][k] < dists[k]) {
                    dists[k] = dists[cur] + graph[cur][k];
                }
            }
        }
        int tminds = INT_MAX, tsum = 0;
        bool is_valid = true;
        for (int i = 1; i <= n; i++) {
            tsum += dists[i];
            if (dists[i] > ds) is_valid = false;
            if (dists[i] < tminds) tminds = dists[i];
        }
        double tavg = 1.0 * tsum / n;
        if (is_valid && (tminds > fminds || (tminds == fminds && tavg < favg))) {
            fminds = tminds;
            favg = tavg;
            fp = i - n;
        }
    }
    if (fp == -1) printf("No Solution\n");
    else printf("G%d\n%.1lf %.1lf\n", fp, fminds, favg);
    return 0;
}

