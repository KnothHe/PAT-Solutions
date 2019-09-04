#include <algorithm>
#include <iostream>
#include <vector>
#include <set>
using namespace std;
int n, k, t, gcnt;
vector<set<int>> gp;
vector<bool> mark;
vector<int> rs;
bool judge(set<int> &s1, set<int> &s2) {
    for (int s : s1) {
        if (s2.find(s) != s2.end()) return true;
    }
    return false;
}
void dfs(int cur) {
    for (int i = 0; i < n; i++) {
        if (!mark[i] && judge(gp[cur], gp[i])) {
            gcnt++;
            mark[i] = true;
            dfs(i);
        }
    }
}
int main() {
    scanf("%d", &n);
    gp.resize(n);
    for (int i = 0; i < n; i++) {
        scanf("%d: ", &k);
        for (int j = 0; j < k; j++) {
            cin >> t;
            gp[i].insert(t);
        }
    }
    mark.resize(n, false);
    for (int i = 0; i < n; i++) {
        if (!mark[i]) {
            mark[i] = true;
            gcnt = 1;
            dfs(i);
            rs.push_back(gcnt);
        }
    }
    sort(rs.begin(), rs.end(), greater<int>());
    cout << rs.size() << "\n";
    if (!rs.empty()) cout << rs[0];
    for (int i = 1; i < rs.size(); i++) {
        cout << " " << rs[i];
    }
    return 0;
}

