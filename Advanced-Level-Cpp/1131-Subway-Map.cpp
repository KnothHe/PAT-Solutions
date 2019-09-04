#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
const int maxn = 100005;
const int fact = 10000;
int n, m, k, s1, s2, src, dst, min_transfer;
vector<vector<int>> gp(maxn);
vector<int> tpath, gpath;
vector<bool> mark(maxn);
unordered_map<int, int> line;
int transfers(vector<int> &path) {
    int cnt = 0, pre_line = -1;
    for (int i = 1; i < path.size(); i++) {
        if (line[path[i-1] * fact + path[i]] != pre_line) { cnt++; }
        pre_line = line[path[i-1] * fact + path[i]];
    }
    return cnt;
}
void dfs(int cur) {
    if (cur == dst) {
        if (gpath.empty() || tpath.size() < gpath.size()
                || (tpath.size() == gpath.size()
                    && transfers(tpath) < min_transfer)) {
            gpath = tpath;
            min_transfer = transfers(tpath);
        }
        return;
    }
    for (int next : gp[cur]) {
        if (!mark[next]) {
            mark[next] = true;
            tpath.push_back(next);
            dfs(next);
            tpath.pop_back();
            mark[next] = false;
        }
    }
}
int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> m >> s1;
        for (int j = 1; j < m; j++) {
            cin >> s2;
            gp[s1].push_back(s2);
            gp[s2].push_back(s1);
            line[s1 * fact + s2] = line[s2 * fact + s1] = i;
            s1 = s2;
        }
    }
    cin >> k;
    for (int i = 0; i < k; i++) {
        cin >> src >> dst;
        mark[src] = true;
        gpath.clear();
        tpath.clear();
        tpath.push_back(src);
        dfs(src);
        mark[src] = false;
        printf("%lu\n", gpath.size() - 1);
        int pre_line = -1, from = src;
        for (int j = 1; j < gpath.size(); j++) {
            if (pre_line != line[gpath[j-1] * fact + gpath[j]]) {
                if (pre_line != -1) {
                    printf("Take Line#%d from %04d to %04d.\n",
                            pre_line, from, gpath[j-1]);
                }
                pre_line = line[gpath[j-1] * fact + gpath[j]];
                from = gpath[j-1];
            }
        }
        printf("Take Line#%d from %04d to %04d.\n",
                pre_line, from, dst);
    }
    return 0;
}

