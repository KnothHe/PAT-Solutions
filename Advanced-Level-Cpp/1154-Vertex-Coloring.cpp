#include <iostream>
#include <vector>
#include <set>
using namespace std;
vector<vector<int>> gp;
vector<int> color;
int n, m, k, u, v;
int main() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        cin >> u >> v;
        gp.push_back({u, v});
    }
    cin >> k;
    color.resize(n);
    for (int i = 0; i < k; i++) {
        set<int> inset;
        for (int j = 0; j < n; j++) {
            cin >> color[j];
            inset.insert(color[j]);
        }
        bool flag = true;
        for (int p = 0; p < gp.size(); p++) {
            if (color[gp[p][0]] == color[gp[p][1]]) { flag = false; }
        }
        if (flag) {
            cout << inset.size() << "-coloring\n";
        } else {
            cout << "No\n";
        }
    }
    return 0;
}

