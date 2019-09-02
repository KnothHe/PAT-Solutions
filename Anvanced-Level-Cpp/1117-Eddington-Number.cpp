#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
int main() {
    int n, e = 0;
    cin >> n;
    vector<int> ns(n);
    for (int i = 0; i < n; i++) { cin >> ns[i]; }
    sort(ns.begin(), ns.end(), greater<int>());
    while (e < n && ns[e] > e + 1) { e++; }
    cout << e;
    return 0;
}

