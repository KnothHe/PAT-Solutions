#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
int main() {
    int n;
    cin >> n;
    vector<int> ns(n);
    for (int i = 0; i < n; i++) { cin >> ns[i]; }
    sort(ns.begin(), ns.end());
    double rs = 0.0;
    if (n > 0) rs = ns[0];
    for (int i = 1; i < n; i++) { rs = (rs + ns[i]) / 2; }
    cout << (int)rs << "\n";
    return 0;
}

