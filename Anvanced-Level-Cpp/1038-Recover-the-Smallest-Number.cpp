/*
 * reference:
 *  https://www.liuchuo.net/archives/2303
 */
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main() {
    int n;
    cin >> n;
    vector<string> ns(n);
    for (int i = 0; i < n; i++) 
        cin >> ns[i];
    sort(ns.begin(), ns.end(), [](auto &lhs, auto &rhs) {
            return lhs + rhs < rhs + lhs;
            });
    string s = "";
    for (auto n : ns) s.append(n);
    while (s.length() != 0 && s[0] == '0')
        s.erase(s.begin());
    if (s.length() == 0) cout << 0;
    cout << s;
    return 0;
}
