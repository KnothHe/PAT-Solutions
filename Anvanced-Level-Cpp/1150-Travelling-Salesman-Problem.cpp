#include <iostream>
#include <vector>
using namespace std;
const int maxn = 205;
int ds[maxn][maxn];
int main() {
    int n, m, c1, c2, dist, k, t;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        cin >> c1 >> c2 >> dist;
        ds[c1][c2] = ds[c2][c1] = dist;
    }
    cin >> k;
    int min_ds = 99999999, min_idx = -1;
    vector<bool> mark(n+1);
    for (int i = 0; i < k; i++) {
        cin >> t;
        vector<int> cs(t);
        for (int j = 0; j < t; j++) {
            cin >> cs[j];
        }
        bool is_cycle = true;
        fill(mark.begin(), mark.end(), false);
        int tds = 0;
        for (int j = 1; j < cs.size(); j++) {
            if (ds[cs[j]][cs[j-1]] > 0) {
                tds += ds[cs[j]][cs[j-1]];
                mark[cs[j]] = true;
            } else { tds = -1; break; }
        }
        for (int j = 1; j < mark.size(); j++) {
            if (!mark[j]) { is_cycle = false; }
        }
        if (cs.front() != cs.back()) { is_cycle = false; }
        if (is_cycle && tds != -1 && tds < min_ds) {
            min_ds = tds; min_idx = i + 1;
        }
        cout << "Path " << i + 1 << ": ";
        if (tds == -1) { cout << "NA (Not a TS cycle)\n"; }
        else if (!is_cycle) {
            cout << tds << " (Not a TS cycle)\n";
        } else {
            if (cs.size() - 1 == n) { cout << tds << " (TS simple cycle)\n"; }
            else { cout << tds << " (TS cycle)\n"; }
        }
    }
    cout << "Shortest Dist(" << min_idx << ") = " << min_ds << "\n";
    return 0;
}

