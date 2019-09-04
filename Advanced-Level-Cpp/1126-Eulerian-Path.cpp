#include <iostream>
#include <vector>
using namespace std;
vector<vector<int>> gp;
vector<bool> mark;
void dfs(int cur) {
    mark[cur] = true;
    for (int next : gp[cur]) {
        if (!mark[next]) dfs(next);
    }
}
int main() {
    int n, m, v1, v2;
    cin >> n >> m;
    gp.resize(n+1);
    mark.resize(n+1, false);
    for (int i = 0; i < m; i++) {
        cin >> v1 >> v2;
        gp[v1].push_back(v2);
        gp[v2].push_back(v1);
    }
    int odd_cnt = 0;
    for (int i = 1; i < gp.size(); i++) {
        if (i != 1) cout << " ";
        cout << gp[i].size();
        if (gp[i].size() % 2 != 0) { odd_cnt++; }
    }
    dfs(1);
    bool connected = true;
    for (int i = 1; i < mark.size(); i++) { if (!mark[i]) connected = false; }
    if (connected) {
        if (odd_cnt == 0) { cout << "\nEulerian\n"; }
        else if (odd_cnt == 2) { cout << "\nSemi-Eulerian\n"; }
    } 
    if (!connected || (odd_cnt != 0 && odd_cnt != 2)) { cout << "\nNon-Eulerian\n"; }
    return 0;
}

