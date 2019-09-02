#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;
struct Peop {
    string id;
    int score;
};
struct Site {
    int num, score;
};
struct Date {
    int site, num;
};
vector<Peop> ps;
unordered_map<int, Site> ss;
unordered_map<int, vector<Date>> ds;
unordered_map<int, unordered_map<int, int>> idx;
int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        string card;
        int score;
        cin >> card >> score;
        ps.push_back({card, score});
        int site = stoi(card.substr(1, 3));
        ss[site].num++;
        ss[site].score += score;
        int date = stoi(card.substr(4, 6));
        if (idx.find(date) == idx.end()
                || idx[date].find(site) == idx[date].end()) {
            ds[date].push_back({site, 1});
            idx[date][site] = ds[date].size() - 1;
        } else {
            ds[date][idx[date][site]].num++;
        }
    }
    sort(ps.begin(), ps.end(), [](auto &lhs, auto &rhs) {
            return lhs.score != rhs.score ? lhs.score > rhs.score : lhs.id < rhs.id;
            });
    for (auto &p : ds) {
        auto &v = p.second;
        sort(v.begin(), v.end(), [](auto &lhs, auto &rhs) {
                return lhs.num != rhs.num ? lhs.num > rhs.num : lhs.site < rhs.site;
                });
    }
    for (int i = 1; i <= m; i++) {
        int type;
        string term;
        cin >> type >> term;
        cout << "Case " << i << ": " << type << " " << term << "\n";
        bool empty = true;
        if (type == 1)  {
            for (auto p : ps) {
                if (p.id[0] == term[0]) {
                    cout << p.id << " " << p.score << "\n";
                    empty = false;
                }
            }
        } else if (type == 2) {
            int site = stoi(term);
            if (ss.find(site) != ss.end()) {
                cout << ss[site].num << " " << ss[site].score << "\n";
                empty = false;
            }
        } else if (type == 3) {
            int date = stoi(term);
            if (!ds[date].empty()) {
                for (auto &d : ds[date]) {
                    cout << d.site << " " << d.num << "\n";
                }
                empty = false;
            }
        }
        if (empty) { cout << "NA\n"; }
    }
    return 0;
}

