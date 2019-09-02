#include <iostream>
#include <vector>
#include <set>
using namespace std;
int main() {
    int n, m, k, t1, t2, nn;
    cin >> n >> m;
    vector<vector<bool>> gp(n+1, vector<bool>(n+1, false));
    for (int i = 0; i < m; i++) {
        cin >> t1 >> t2;
        gp[t1][t2] = gp[t2][t1] = true;
    }
    cin >> k;
    for (int i = 0; i < k; i++) {
        cin >> nn;
        vector<int> ts(nn);
        for (int i = 0; i < nn; i++) {
            cin >> ts[i];
        }
        set<int> inset;
        if (ts.size() != n+1 || ts.front() != ts.back()) { cout << "NO\n"; }
        else {
            bool flag = true;
            for (int i = 0; i < ts.size()-1; i++) {
                if (!gp[ts[i]][ts[i+1]]) {
                    flag = false;
                    break;
                }
                inset.insert(ts[i]);
            }
            if (flag && inset.size() == n) { cout << "YES\n"; }
            else { cout << "NO\n"; }
        }
    }
    return 0;
}

