#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
const int maxn = 105;
int n;
vector<int> ns(maxn);
bool judge(int w1, int w2) {
    int wcnt = 0, hcnt = 0;
    if (ns[w1] > 0 && w2 == abs(ns[w1])) { wcnt++; }
    else if (ns[w1] < 0 && w2 != abs(ns[w1])) { wcnt++; }
    if (ns[w2] > 0 && w1 == abs(ns[w2])) { wcnt++; }
    else if (ns[w2] < 0 && w1 != abs(ns[w2])) { wcnt++; }
    for (int i = 1; i <= n; i++) {
        if (i != w1 && i != w2) {
            if (ns[i] > 0 && (w1 == abs(ns[i]) || w2 == abs(ns[i]))) { hcnt++; }
            else if (ns[i] < 0 && (w1 != abs(ns[i]) && w2 != abs(ns[i]))) { hcnt++; }
        }
    }
    if (wcnt == 1 && hcnt == 1) return true;
    return false;
}
int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) { cin >> ns[i]; }
    vector<vector<int>> rs;
    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            if (judge(i, j)) {
                cout << i << " " << j << "\n";
                return 0;
            }
        }
    }
    cout << "No Solution\n";
    return 0;
}

