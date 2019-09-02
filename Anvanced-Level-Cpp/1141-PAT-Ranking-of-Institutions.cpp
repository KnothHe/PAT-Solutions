#include <algorithm>
#include <iostream>
#include <vector>
#include <unordered_map>
#include <cctype>
using namespace std;
struct Sch {
    string sch;
    int rank, ns;
    double tws;
};
unordered_map<string, int> schidx;
int main() {
    int n;
    cin >> n;
    vector<Sch> schs;
    for (int i = 0; i < n; i++) {
        string id, sch;
        double score;
        cin >> id >> score >> sch;
        if (id[0] == 'B') { score /= 1.5; }
        if (id[0] == 'T') { score *= 1.5; }
        for (char &ch : sch) { ch = tolower(ch); }
        if (schidx.find(sch) == schidx.end()) {
            schs.push_back({sch, -1, 0, 0.0});
            schidx[sch] = schs.size() - 1;
        }
        schs[schidx[sch]].tws += score;
        schs[schidx[sch]].ns++;
    }
    sort(schs.begin(), schs.end(), [](auto &lhs, auto &rhs) {
            return (int)lhs.tws != (int)rhs.tws ? (int)lhs.tws > (int)rhs.tws :
            (lhs.ns != rhs.ns ? lhs.ns < rhs.ns : lhs.sch < rhs.sch);
            });
    if (!schs.empty()) schs[0].rank = 1;
    int rank = 1;
    for (int i = 1; i < schs.size(); i++) {
        if ((int)schs[i].tws != (int)schs[i-1].tws) { rank = i+1; }
        schs[i].rank = rank;
    }
    cout << schs.size() << "\n";
    for (auto &s : schs) {
        cout << s.rank << " " << s.sch << " " << (int)s.tws << " " << s.ns << "\n";
    }
    return 0;
}

