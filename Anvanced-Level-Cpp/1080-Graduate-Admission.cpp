#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
struct Appl {
    int id, ge, gi, fg;
    vector<int> schs;
};
int main() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<Appl> aps(n);
    vector<int> qus(m);
    for (int i = 0; i < m; i++) {
        cin >> qus[i];
    }
    for (int i = 0; i < n; i++) {
        auto &ap = aps[i];
        cin >> ap.ge >> ap.gi;
        ap.id = i;
        ap.fg = ap.ge + ap.gi;
        ap.schs.resize(k);
        for (int j = 0; j < k; j++) {
            cin >> ap.schs[j];
        }
    }
    sort(aps.begin(), aps.end(), [](auto &lhs, auto &rhs) {
            return lhs.fg != rhs.fg ? lhs.fg > rhs.fg : lhs.ge > rhs.ge;
            });
    vector<vector<Appl>> rs(m);
    for (auto ap : aps) {
        for (auto sch : ap.schs) {
            auto &r = rs[sch];
            if (rs[sch].size() < qus[sch] ||
                    (ap.fg == r.back().fg && ap.ge == r.back().ge)) {
                rs[sch].push_back(ap);
                break;
            }
        }
    }
    for (auto &r : rs) {
        sort(r.begin(), r.end(), [](auto &lhs, auto &rhs) {
                return lhs.id < rhs.id;
                });
        if (!r.empty()) cout << r[0].id;
        for (int i = 1; i < r.size(); i++) cout << " " << r[i].id;
        cout << "\n";
    }
    return 0;
}

