/*
 * Reference: https://www.mmuaa.com/post/4e52061f198bb20f.html
 *
 */
#include <iostream>
#include <vector>
using namespace std;
int main() {
    int k, n, t;
    cin >> k;
    for (int i = 0; i < k; i++) {
        cin >> n;
        vector<bool> row(n + 1), dig(2 * (n + 1) + 1);
        bool flag = true;
        for (int j = 0; j < n; j++) {
            cin >> t;
            if (row[t] || dig[t + j]) { flag = false; }
            row[t] = dig[t + j] = true;
        }
        if (flag) { cout << "YES\n"; }
        else { cout << "NO\n"; }
    }
}

