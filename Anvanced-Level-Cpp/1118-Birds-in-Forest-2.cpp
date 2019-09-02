#include <iostream>
#include <vector>
#include <set>
using namespace std;
const int maxn = 100005;
int id[maxn];
vector<vector<int>> gp(maxn);
set<int> inset;
vector<bool> mark(maxn, false);
void dfs(int cur, int rid) {
    mark[cur] = true;
    id[cur] = rid;
    for (int next : gp[cur]) {
        if (!mark[next]) {
            dfs(next, rid);
        }
    }
}
int main() {
    for (int i = 0; i < maxn; i++) { id[i] = -1; }
    int n, k, t, root, q, q1, q2, gcnt = 0;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> k;
        for (int j = 0; j < k; j++) {
            cin >> t;
            if (j == 0) { root = t; }
            else {
                gp[root].push_back(t);
                gp[t].push_back(root);
            }
            inset.insert(t);
        }
    }
    for (int i = 0; i < maxn; i++) {
        if (!mark[i] && inset.find(i) != inset.end()) {
            gcnt++;
            dfs(i, i);
        }
    }
    cout << gcnt << " " << inset.size() << "\n";
    cin >> q;
    for (int i = 0; i < q; i++) {
        cin >> q1 >> q2;
        if (id[q1] == id[q2] && id[q1] > 0) { cout << "Yes\n"; }
        else { cout << "No\n"; }
    }
    return 0;
}

