/*
 * Simple dfs
 *
 */
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
int n, t, gdep = -1, cnt, root;
double p, r;
vector<vector<int>> gp;
void dfs(int cur, int tdep) {
    if (gp[cur].empty()) {
        if (tdep > gdep) {
            gdep = tdep;
            cnt = 1;
        } else if (tdep == gdep) { cnt++; }
    }
    for (auto next : gp[cur]) { dfs(next, tdep + 1); }
}
int main() {
    cin >> n >> p >> r;
    r /= 100;
    gp.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> t;
        if (t != -1) gp[t].push_back(i);
        else root = i;
    }
    dfs(root, 0);
    printf("%.2lf %d", pow(1+r, gdep) * p, cnt);
}

