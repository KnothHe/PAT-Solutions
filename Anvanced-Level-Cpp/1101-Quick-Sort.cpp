#include <iostream>
#include <vector>
using namespace std;
int main() {
    int n;
    cin >> n;
    vector<int> ns(n), rs;
    for (int i = 0; i < n; i++) {
        cin >> ns[i];
    }
    vector<bool> flag(n, true);
    int min_val = ns.back(), max_val = ns.front();
    for (int i = ns.size() - 1; i >= 0; i--) {
        if (ns[i] <= min_val) {
            min_val = ns[i];
        } else {
            flag[i] = false;
        }
    }
    for (int i = 0; i < ns.size(); i++) {
        if (ns[i] >= max_val) {
            max_val = ns[i];
        } else {
            flag[i] = false;
        }
        if (flag[i]) rs.push_back(ns[i]);
    }
    cout << rs.size() << "\n";
    if (!rs.empty()) cout << rs[0];
    for (int i = 1; i < rs.size(); i++) {
        cout << " " << rs[i];
    }
    cout << "\n";
    return 0;
}
