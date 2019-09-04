/*
 * Reference:
 *  https://www.liuchuo.net/archives/2301
 */
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
int main() {
    int n, cnt = 0, t;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> t;
        a[t] = i;
    }
    for (int i = 1; i < n; i++) {
        if (a[i] != i) {
            while (a[0] != 0) {
                swap(a[0] ,a[a[0]]);
                cnt++;
            }
            if (a[i] != i) {
                swap(a[0], a[i]);
                cnt++;
            }
        }
    }
    cout << cnt;
    return 0;
}

