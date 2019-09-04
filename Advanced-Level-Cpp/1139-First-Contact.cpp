#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;
bool same_gend(string &p1, string &p2) {
    return ((p1[0] == '-' && p2[0] == '-')
            || (p1[0] != '-' && p2[0] != '-'));
}
string to_pos(string s) {
    return s[0] == '-' ? s.substr(1) : s;
}
int main() {
    int n, m, k;
    string p1, p2;
    cin >> n >> m;
    unordered_map<string, unordered_set<string>> fd;
    for (int i = 0; i < m; i++) {
        cin >> p1 >> p2;
        fd[p1].insert(p2);
        fd[p2].insert(p1);
    }
    cin >> k;
    for (int i = 0; i < k; i++) {
        cin >> p1 >> p2;
        unordered_set<string> fds1, fds2;
        vector<vector<string>> rs;
        if (fd.find(p1) != fd.end() && fd.find(p2) != fd.end()) {
            for (string f : fd[p1]) {
                if (same_gend(p1, f) && f != p2) { fds1.insert(f); }
            }
            for (string f : fd[p2]) {
                if (same_gend(p2, f) && f != p1) { fds2.insert(f); }
            }
            for (string f1 : fds1) {
                for (string f2 : fds2) {
                    if (fd[f1].find(f2) != fd[f1].end()) {
                        rs.push_back({to_pos(f1), to_pos(f2)});
                    }
                }
            }
        }
        sort(rs.begin(), rs.end(), [](auto &lhs, auto &rhs) {
                return lhs[0] != rhs[0] ? lhs[0] < rhs[0] : lhs[1] < rhs[1];
                });
        cout << rs.size() << "\n";
        for (auto &r : rs) { cout << r[0] << " " << r[1] << "\n"; }
    }
    return 0;
}

