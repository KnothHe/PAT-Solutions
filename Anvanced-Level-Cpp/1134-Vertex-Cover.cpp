#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;
struct Edge {
    int v1, v2;
};
int main() {
    int n, m, k, q, v1, v2, v;
    cin >> n >> m;
    vector<Edge> es;
    for (int i = 0; i < m; i++) {
        cin >> v1 >> v2;
        es.push_back({ v1, v2 });
    }
    cin >> k;
    for (int i = 0; i < k; i++) {
        cin >> q;
        unordered_set<int> vs;
        for (int j = 0; j < q; j++) {
            cin >> v;
            vs.insert(v);
        }
        bool flag = true;
        for (auto &e : es) {
            if (vs.find(e.v1) == vs.end() && vs.find(e.v2) == vs.end()) {
                flag = false;
            }
        }
        if (flag) { cout << "Yes\n"; }
        else { cout << "No\n"; }
    }
    return 0;
}

