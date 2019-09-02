#include <algorithm>
#include <iostream>
#include <vector>
#include <set>
using namespace std;
const int maxn = 100005;
struct Est {
    int sets = 0, area = 0;
};
struct Res {
    int min_idx, num;
    double savg, aavg;
};
Est est[maxn];
bool mark[maxn];
vector<vector<int>> gp(maxn);
vector<vector<int>> fams;
set<int> inset;
int sets, area, gcnt;
void dfs(int cur) {
    mark[cur] = true;
    gcnt++;
    sets += est[cur].sets;
    area += est[cur].area;
    for (int next : gp[cur]) { if (!mark[next]) { dfs(next); } }
}
int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int id, fa, mo, k, kid;
        cin >> id >> fa >> mo >> k;
        inset.insert(id);
        if (fa != -1) {
            gp[fa].push_back(id);
            gp[id].push_back(fa);
            inset.insert(fa);
        }
        if (mo != -1) {
            gp[mo].push_back(id);
            gp[id].push_back(mo);
            inset.insert(mo);
        }
        for (int j = 0; j < k; j++) {
            cin >> kid;
            gp[kid].push_back(id);
            gp[id].push_back(kid);
            inset.insert(kid);
        }
        cin >> est[id].sets >> est[id].area;
    }
    vector<Res> rs;
    for (int i = 0; i < maxn; i++) {
        if (!mark[i] && inset.find(i) != inset.end()) {
            sets = 0;
            area = 0;
            gcnt = 0;
            dfs(i);
            rs.push_back({ i, gcnt, (double)sets / gcnt, (double)area / gcnt });
        }
    }
    sort(rs.begin(), rs.end(), [](auto &lhs, auto &rhs) {
            return lhs.aavg != rhs.aavg ? lhs.aavg > rhs.aavg :
                lhs.min_idx < rhs.min_idx;
            });
    printf("%zu\n", rs.size());
    for (auto r : rs) {
        printf("%04d %d %.3lf %.3lf\n", r.min_idx, r.num, r.savg, r.aavg);
    }
    return 0;
}

