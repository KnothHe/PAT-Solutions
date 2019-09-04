#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
const int maxn = 10005;
int pre[maxn], in[maxn];
unordered_map<int, int> key;
int main() {
    int m, n, u, v;
    scanf("%d %d", &m, &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &in[i]);
        key[in[i]] = i + 1;
    }
    for (int i = 0; i < n; i++) { scanf("%d", &pre[i]); }
    for (int i = 0; i < m; i++) {
        cin >> u >> v;
        if (key[u] == 0 && key[v] == 0) {
            printf("ERROR: %d and %d are not found.\n", u, v);
        } else if (key[u] == 0 || key[v] == 0) {
            printf("ERROR: %d is not found.\n", key[u] == 0 ? u : v);
        } else {
            int c;
            for (int j = 0; j < n; j++) {
                c = pre[j];
                if ((key[c] >= key[u] && key[c] <= key[v])
                        || (key[c] >= key[v] && key[c] <= key[u])) {
                    break;
                }
            }
            if (c == u || c == v) {
                printf("%d is an ancestor of %d.\n", c == u ? u : v, c == u ? v : u);
            } else {
                printf("LCA of %d and %d is %d.\n", u, v, c);
            }
        }
    }
    return 0;
}

