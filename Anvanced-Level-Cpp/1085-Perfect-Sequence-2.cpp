/*
 * Reference:
 *  https://www.liuchuo.net/archives/1908
 *
 * Use binary search (upper_bound).
*
 */
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
int main() {
    int n, p;
    cin >> n >> p;
    vector<ll> ns(n);
    for (int i = 0; i < n; i++) {
        cin >> ns[i];
    }
    sort(ns.begin(), ns.end());
    int maxn = 0;
    for (int i = 0; i < ns.size(); i++) {
        maxn = max(maxn, static_cast<int>(upper_bound(ns.begin(), ns.end(),
                    ns[i] * p) - ns.begin() - i));
    }
    cout << maxn;
    return 0;
}

