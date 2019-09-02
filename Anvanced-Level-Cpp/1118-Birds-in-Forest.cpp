#include <iostream>
#include <vector>
#include <set>
using namespace std;
const int maxn = 100005;
int id[maxn], sz[maxn];
set<int> inset, tcnt;
int find(int x) {
    while (id[x] != x) x = id[x];
    return x;
}
void uni(int a, int b) {
    int ra = find(a);
    int rb = find(b);
    if (sz[ra] < sz[rb]) { id[ra] = id[rb]; sz[rb] += sz[ra]; }
    else { id[rb] = id[ra]; sz[ra] += sz[rb]; }
}
int main() {
    for (int i = 0; i < maxn; i++) { id[i] = i; }
    for (int i = 0; i < maxn; i++) { sz[i] = 1; }
    int n, k, q, t, root, q1, q2;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> k;
        for (int j = 0; j < k; j++) {
            cin >> t;
            if (j == 0) { root = t; } 
            else { uni(root, t); }
            inset.insert(t);
        }
    }
    for (int i = 0; i < maxn; i++) {
        if (inset.find(i) != inset.end()) {
            int r = find(i);
            tcnt.insert(r);
        }
    }
    cout << tcnt.size() << " " << inset.size() << "\n";
    cin >> q;
    for (int i = 0; i < q; i++) {
        cin >> q1 >> q2;
        if (find(q1) == find(q2)) { cout << "Yes\n"; }
        else { cout << "No\n"; }
    }
    return 0;
}

