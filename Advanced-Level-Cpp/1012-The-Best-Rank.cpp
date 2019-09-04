#include <algorithm>
#include <iostream>
#include <vector>
#include <map>
using namespace std;
struct Stud {
    vector<int> gs;
    int best_idx, best_rank = 1 << 7;
    string id;
    Stud(string id, int c, int m, int e) :
        id(id), gs{ static_cast<int>((c + m + e) / 3.0 + 0.5), c, m, e} {  };
};
void give_rank(vector<Stud> &studs, int r) {
    sort(studs.begin(), studs.end(), [r](auto &lhs, auto &rhs) {
            return lhs.gs[r] > rhs.gs[r];
            });
    int rank = 1;
    if (studs[0].best_rank > 1) {
        studs[0].best_rank = 1;
        studs[0].best_idx = r;
    }
    for (int i = 1; i < studs.size(); i++) {
        if (studs[i].gs[r] != studs[i - 1].gs[r]) { rank = i + 1; }
        if (rank < studs[i].best_rank) {
            studs[i].best_rank = rank;
            studs[i].best_idx = r;
        }
    }
}
int main() {
    string R = "ACME";
    int n, m;
    string id;
    cin >> n >> m;
    vector<Stud> studs;
    for (int i = 0; i < n; i++) {
        int tc, tm, te;
        cin >> id >> tc >> tm >> te;
        studs.push_back({id, tc, tm, te});
    }
    for (int i = 0; i < 4; i++) {
        give_rank(studs, i);
    }
    map<string, int> idxs;
    for (int i = 0; i < n; i++) {
        idxs[studs[i].id] = i;
    }
    for (int i = 0; i < m; i++) {
        cin >> id;
        if (idxs.find(id) != idxs.end()) {
            cout << studs[idxs[id]].best_rank << " " << R[studs[idxs[id]].best_idx];
        } else {
            cout << "N/A";
        }
        cout << "\n";
    }
    return 0;
}

