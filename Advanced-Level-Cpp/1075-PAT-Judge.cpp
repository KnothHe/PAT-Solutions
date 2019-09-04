/*
 * Simple sort
 */
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
struct User {
    bool submit = false;
    int id, score = 0, rank, pref;
    vector<int> ss;
    User() : ss(5, -2) {  }
} user;
int main() {
    int n, k, m;
    cin >> n >> k >> m;
    vector<int> p(k);
    vector<User> us(n);
    for (int i = 0; i < k; i++) { cin >> p[i]; }
    for (int i = 0; i < m; i++) {
        int id, pid, score;
        cin >> id >> pid >> score;
        auto &u = us[id - 1];
        u.id = id;
        u.ss[pid - 1] = max(u.ss[pid - 1], score);
        if (score != -1) u.submit = true;
    }
    us.erase(remove_if(us.begin(), us.end(), [](auto &e) { return e.submit == false; }), 
            us.end());
    for (auto &u : us) {
        int pref = 0;
        for (int i = 0; i < k; i++) { 
            if (u.ss[i] == p[i]) pref++; 
            if (u.ss[i] > 0) u.score += u.ss[i];
        }
        u.pref = pref;
    }
    sort(us.begin(), us.end(), [](auto &lhs, auto &rhs) {
            return lhs.score != rhs.score ? lhs.score > rhs.score :
                (lhs.pref != rhs.pref ? lhs.pref > rhs.pref : lhs.id < rhs.id);
            });
    int r = 1;
    us[0].rank = 1;
    for (int i = 1; i < us.size(); i++) {
        if (us[i].score == us[i-1].score) us[i].rank = r;
        else {
            r = i + 1;
            us[i].rank = r;
        }
    }
    for (auto u : us) {
        printf("%d %05d %d", u.rank, u.id, u.score);
        for (int i = 0; i < k; i++) {
            if (u.ss[i] == -2) printf(" -");
            else if (u.ss[i] == -1) printf(" 0");
            else printf(" %d", u.ss[i]);
        }
        printf("\n");
    }
}

