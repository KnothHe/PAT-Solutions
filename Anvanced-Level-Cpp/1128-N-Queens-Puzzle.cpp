#include <iostream>
#include <vector>
using namespace std;
const int maxn = 1005;
bool cb[maxn][maxn];
bool check(int n) {
    for (int p = 0; p < n; p++) {
        for (int q = 0; q < n; q++) {
            if (cb[p][q]) {
                int r = p + 1, c = q + 1;
                while (r < n && c < n) {
                    if (cb[r][c]) { return false; }
                    r++; c++;
                }
                r = p + 1; c = q - 1;
                while (r < n && c >= 0) {
                    if (cb[r][c]) { return false; }
                    r++; c--;
                }
                r = p - 1; c = q + 1;
                while (r >= 0 && c < n) {
                    if (cb[r][c]) { return false; }
                    r--; c++;
                }
                r = p - 1; c = q - 1;
                while (r >= 0 && c >= 0) {
                    if (cb[r][c]) { return false; }
                    r--; c--;
                }
                c = q - 1;
                while (c >= 0) {
                    if (cb[p][c]) { return false; }
                    c--;
                }
                c = q + 1;
                while (c < n) {
                    if (cb[p][c]) { return false; }
                    c++;
                }
            }
        }
    }
    return true;
}
int main() {
    int k, n, t;
    cin >> k;
    for (int i = 0; i < k; i++) {
        fill(cb[0], cb[0] + maxn * maxn, false);
        cin >> n;
        for (int j = 0; j < n; j++) {
            cin >> t;
            cb[t-1][j] = true;
        }
        if (check(n)) { cout << "YES\n"; }
        else { cout << "NO\n"; }
    }
    return 0;
}

