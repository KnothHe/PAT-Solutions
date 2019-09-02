/*
 * Reference: https://www.liuchuo.net/archives/2451
 *
 */
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
int n, k, p, gfacsum = -1;
vector<int> v, trs, rs;
void dfs(int cval, int csum, int ck, int tfacsum) {
    if (ck == k) {
        if (csum == n && tfacsum > gfacsum) {
            rs = trs;
            gfacsum = tfacsum;
        }
        return;
    }
    while (cval >= 1) {
        if (csum + v[cval] <= n) {
            trs[ck] = cval;
            dfs(cval, csum + v[cval], ck + 1, tfacsum + cval);
        }
        cval--;
    }
}
int main() {
    cin >> n >> k >> p;
    for (int i = 1, t = 0; t <= n; i++) {
        v.push_back(t);
        t = pow(i, p);
    }
    trs.resize(k);
    dfs(v.size() - 1, 0, 0, 0);
    if (gfacsum == -1) { cout << "Impossible"; return 0; }
    cout << n << " = ";
    if (!rs.empty()) cout << rs[0] << "^" << p;
    for (int i = 1; i < rs.size(); i++) {
        cout << " + " << rs[i] << "^" << p;
    }
    return 0;
}

