/*
 * Merge part refer https://www.liuchuo.net/archives/1902
 *
 */
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
int main() {
    int n;
    cin >> n;
    vector<int> ns(n), pa(n);
    for (int i = 0; i < n; i++) { cin >> ns[i]; }
    for (int i = 0; i < n; i++) { cin >> pa[i]; }
    int idx = 1;
    while (idx < n && pa[idx] >= pa[idx-1]) { idx++; }
    while (idx < n && ns[idx] == pa[idx]) { idx++; }
    if (idx == n) {
        cout << "Insertion Sort\n";
        for (idx = 1; pa[idx] >= pa[idx-1]; idx++) {  }
        sort(ns.begin(), ns.begin() + idx + 1);
    } else {
        cout << "Merge Sort\n";
        bool flag = true;
        int sz = 1;
        while (flag) {
            flag = false;
            for (int i = 0; i < n; i++) {
                if (ns[i] != pa[i]) flag = true;
            }
            sz = sz * 2;
            for (int i = 0; i < n / sz; i++)
                sort(ns.begin() + i * sz, ns.begin() + (i + 1) * sz);
            sort(ns.begin() + n / sz * sz, ns.end());
        }
    }
    cout << ns[0];
    for (int i = 1; i < n; i++) cout << " " << ns[i];
    return 0;
}

