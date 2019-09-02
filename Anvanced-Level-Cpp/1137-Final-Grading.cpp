#include <algorithm>
#include <iostream>
#include <vector>
#include <map>
using namespace std;
struct Stud {
    string id;
    int gp, gmid, gfin, g;
};
map<string, int> ma;
int main() {
    int p, m, n, gp, gmid, gfin;
    string id;
    cin >> p >> m >> n;
    vector<Stud> studs;
    for (int i = 0; i < p; i++) {
        cin >> id >> gp;
        if (gp >= 200) {
            studs.push_back({id, gp, -1, -1, 0});
            ma[id] = studs.size() - 1;
        }
    }
    for (int i = 0; i < m; i++) {
        cin >> id >> gmid;
        if (ma.find(id) != ma.end()) {
            studs[ma[id]].gmid = gmid;
        }
    }
    for (int i = 0; i < n; i++) {
        cin >> id >> gfin;
        if (ma.find(id) != ma.end()) {
            auto &s = studs[ma[id]];
            s.gfin = gfin;
            s.g = s.gfin >= s.gmid ? s.gfin :
                s.gmid * 0.4 + s.gfin * 0.6 + 0.5;
        }
    }
    sort(studs.begin(), studs.end(), [](auto &lhs, auto &rhs) {
            return lhs.g != rhs.g ? lhs.g > rhs.g : lhs.id < rhs.id;
            });
    for (auto &s : studs) {
        if (s.g >= 60)
            cout << s.id << " " << s.gp << " " << s.gmid << " "
                << s.gfin << " " << s.g << "\n";
    }
    return 0;
}

