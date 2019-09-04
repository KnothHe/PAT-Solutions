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
    int mid = ns.size() / 2, sum1 = 0, sum2 = 0;
    for (int i = 0; i < mid; i++) {
        sum1 += ns[i];
    }
    for (int i = mid; i < ns.size(); i++) {
        sum2 += ns[i];
    }
    cout << ns.size() % 2 << " " << sum2 - sum1 << "\n";
    return 0;
}

