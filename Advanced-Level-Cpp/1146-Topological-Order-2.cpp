#include <iostream>
#include <vector>
using namespace std;
int main() {
    int n, m, u, v, k, t;
    cin >> n >> m;
    vector<vector<int>> gp(n+1);
    vector<int> in(n+1), rs;
    for (int i = 0; i < m; i++) {
        cin >> u >> v;
        gp[u].push_back(v);
        in[v]++;
    }
    cin >> k;
    bool space = false;
    for (int i = 0; i < k; i++) {
        vector<int> tin(in.begin(), in.end());
        bool is_tod = true;
        for (int j = 0; j < n; j++) {
            cin >> t;
            if (tin[t] != 0) { is_tod = false; }
            for (int next : gp[t]) { tin[next]--; }
        }
        if (!is_tod) {
            if (space) cout << " ";
            cout << i;
            space = true;
        }
    }
    return 0;
}

