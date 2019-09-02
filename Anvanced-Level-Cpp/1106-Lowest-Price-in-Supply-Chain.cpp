#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int n, k, t, gcnt;
double p, r, fp = -1.0;
vector<vector<int>> gp;
void dfs(int cur, double cp) {
    if (gp[cur].empty()) {
        if (fp == -1.0 || cp < fp) {
            fp = cp;
            gcnt = 1;
        } else if (cp == fp) {
            gcnt++;
        }
        return;
    }
    for (int next : gp[cur]) {
        dfs(next, (1 + r) * cp);
    }
}
int main() {
    cin >> n >> p >> r;
    r /= 100;
    gp.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> k;
        for (int j = 0; j < k; j++) {
            cin >> t;
            gp[i].push_back(t);
        }
    }
    dfs(0, p);
    printf("%.4lf %d", fp, gcnt);
    return 0;
}

