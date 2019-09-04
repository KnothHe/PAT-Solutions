/*
 * Save all people who meet the conditions to array ps, 
 * give each people a type according to their virtue and talent.
 *
 * When sorting, first consider type, then total grade, then virtue, then id.
 *
 */
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
struct Peop {
    string id;
    int type;
    int virtue, talent;
} p;
int main() {
    int n, l, h;
    vector<Peop> ps;
    cin >> n >> l >> h;
    for (int i = 0; i < n; i++) {
        cin >> p.id >> p.virtue >> p.talent;
        if (p.virtue >= l && p.talent >= l) {
            if (p.virtue >= h && p.talent >= h) p.type = 1;
            else if (p.virtue >= h) p.type = 2;
            else if (p.virtue >= p.talent) p.type = 3;
            else p.type = 4;
            ps.push_back(p);
        }
    }
    sort(ps.begin(), ps.end(), [](auto &lhs, auto &rhs) {
            int la = lhs.talent + lhs.virtue;
            int ra = rhs.talent + rhs.virtue;
            return lhs.type != rhs.type ? lhs.type < rhs.type :
            (la != ra ? la >= ra : 
             (lhs.virtue != rhs.virtue ? lhs.virtue > rhs.virtue :
              lhs.id < rhs.id));
            });
    cout << ps.size() << endl;
    for (auto &p : ps) {
        cout << p.id << " " << p.virtue << " " << p.talent << endl;
    }
    return 0;
}

