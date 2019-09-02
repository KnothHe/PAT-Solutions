#include <iostream>
#include <vector>
#include <map>
#include <set>
using namespace std;
int ns[1005];
int main() {
    int n, m, p1, p2, k, t;
    scanf("%d %d", &n, &m);
    map<int, set<int>> pairs;
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &p1, &p2);
        pairs[p1].insert(p2);
        pairs[p2].insert(p1);
    }
    for (int i = 0; i < m; i++) {
        scanf("%d", &k);
        int idx = 0;
        for (int j = 0; j < k; j++) {
            scanf("%d", &t);
            if (pairs.find(t) != pairs.end()) { ns[idx++] = t; }
        }
        bool can = true;
        for (int p = 0; p < idx; p++) {
            if (can) {
                for (int q = p + 1; q < idx; q++) {
                    if (pairs[ns[p]].find(ns[q]) != pairs[ns[p]].end()) {
                        can = false;
                    }
                }
            }
        }
        if (can) { cout << "Yes\n"; }
        else { cout << "No\n"; }
    }
    return 0;
}

