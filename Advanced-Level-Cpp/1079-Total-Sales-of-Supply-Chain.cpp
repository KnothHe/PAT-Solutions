#include <iostream>
#include <vector>
using namespace std;
struct Role {
    int type; // 0 supplier / distributor, 1 retailer
    int amo; // only retailer will have
    vector<int> chain;
};
int n, k, t;
double p, r, fsum = 0.0;
vector<Role> rls;
void dfs(int cur, double tp) {
    if (rls[cur].type == 1) {
        fsum += rls[cur].amo * tp;
        return;
    }
    for (auto next : rls[cur].chain) {
        dfs(next, (1 + r) * tp);
    }
}
int main() {
    cin >> n >> p >> r;
    rls.resize(n);
    r /= 100.0;
    for (int i = 0; i < n; i++) {
        auto &r = rls[i];
        cin >> k;        
        if (k != 0) {
            for (int i = 0; i < k; i++) {
                cin >> t;
                r.chain.push_back(t);
                r.type = 0;
            }
        } else {
            cin >> t;
            r.type = 1;
            r.amo = t;
        }
    }
    dfs(0, p);
    printf("%.1f\n", fsum);
    return 0;
}

