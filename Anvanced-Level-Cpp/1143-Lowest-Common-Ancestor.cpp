#include <iostream>
#include <vector>
#include <set>
using namespace std;
set<int> inset;
int main() {
    int m, n, u, v, c;
    scanf("%d %d", &m, &n);
    vector<int> pre(n);
    for (int i = 0; i < n; i++) {
        cin >> pre[i];
        inset.insert(pre[i]);
    }
    for (int i = 0; i < m; i++) {
        scanf("%d %d", &u, &v);
        for (int j = 0; j < n; j++) {
            c = pre[j];
            if ((c >= u && c <= v) || (c >= v && c <= u)) { break; }
        }
        if (inset.find(u) == inset.end() && inset.find(v) == inset.end()) {
            printf("ERROR: %d and %d are not found.\n", u, v);
        } else if (inset.find(u) == inset.end() || inset.find(v) == inset.end()) {
            printf("ERROR: %d is not found.\n", inset.find(u) == inset.end() ? u : v);
        } else if (c == u || c == v) {
            printf("%d is an ancestor of %d.\n", c, c == u ? v : u);
        } else {
            printf("LCA of %d and %d is %d.\n", u, v, c);
        }
    }
    return 0;
}

