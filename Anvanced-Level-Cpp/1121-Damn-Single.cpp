#include <iostream>
#include <vector>
#include <set>
using namespace std;
const int maxn = 1000005;
int main() {
    vector<int> cp(maxn, -1);
    int n, m, t1, t2, t;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> t1 >> t2;
        cp[t1] = t2;
        cp[t2] = t1;
    }
    cin >> m;
    set<int> guests;
    for (int i = 0; i < m; i++) {
        cin >> t;
        guests.insert(t);
    }
    vector<int> rs;
    for (int guest : guests) {
        if (cp[guest] == -1 || guests.find(cp[guest]) == guests.end()) {
            rs.push_back(guest);
        }
    }
    printf("%zu\n", rs.size());
    if (!rs.empty()) { printf("%05d", rs[0]); }
    for (int i = 1; i < rs.size(); i++) { printf(" %05d", rs[i]); }
    return 0;
}

