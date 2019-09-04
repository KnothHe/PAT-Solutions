#include <iostream>
#include <vector>
#include <set>
using namespace std;
const int maxn = 205;
int nv, ne, v1, v2, m, k;
bool gp[maxn][maxn];
bool is_cliq(vector<int> &c) {
    for (int i = 0; i < c.size(); i++) {
        for (int j = i+1; j < c.size(); j++)  {
            if (!gp[c[i]][c[j]]) return false;
        }
    }
    return true;
}
bool is_max_cliq(vector<int> &cliq) {
    set<int> inset;
    for (int c : cliq) { inset.insert(c); }
    for (int i = 1; i <= nv; i++) {
        if (inset.find(i) == inset.end()) {
            bool flag = true;
            for (int j = 0; j < cliq.size(); j++) {
                if (!gp[i][cliq[j]]) {
                    flag =false;
                    break;
                }
            }
            if (flag) return false;
        }
    }
    return true;
}
int main() {
    cin >> nv >> ne;
    for (int i = 0; i < ne; i++) {
        cin >> v1 >> v2;
        gp[v1][v2] = gp[v2][v1] = true;
    }
    cin >> m;
    for (int i = 0; i < m; i++) {
        cin >> k;
        vector<int> cliq(k);
        for (int j = 0; j < k; j++) {
            cin >> cliq[j];
        }
        if (is_cliq(cliq)) {
            if (is_max_cliq(cliq)) { cout << "Yes\n"; }
            else { cout << "Not Maximal\n"; }
        } else { cout << "Not a Clique\n"; }
    }
    return 0;
}

