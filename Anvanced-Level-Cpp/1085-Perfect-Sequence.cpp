/*
 * Sort the array first, then iterate the array to 
 * find the position of largest M for each location.
 * 
 * Note:
 *  1. we can reuse last break position.
 *  2. if last break position reach end, then just break.
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
    int maxn = 0, last_break = -1;
    for (int i = 0; i < ns.size(); i++) {
        int r;
        if (last_break == -1) {
            for (r = ns.size() - 1; r >= i; r--) { 
                if (ns[r] <= ns[i] * p) { break; } 
            }
        } else {
            for (r = last_break; ns[r] <= ns[i] * p && r < ns.size(); r++) { }
            r--;
        }
        last_break = r;
        maxn = max(maxn, r - i + 1);
        if (r == ns.size() - 1) break;
    }
    cout << maxn;
    return 0;
}

