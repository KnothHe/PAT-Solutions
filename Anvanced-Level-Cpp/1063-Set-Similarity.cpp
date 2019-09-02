#include <algorithm>
#include <set>
#include <vector>
#include <cstdio>
using namespace std;
int main() {
    int n, m, t;
    scanf("%d", &n);
    vector<set<int>> sets(n, set<int>());
    for (int i = 0; i < n; i++) {
        scanf("%d", &m);
        for (int j = 0; j < m; j++) {
            scanf("%d", &t);
            sets[i].insert(t);
        }
    }
    scanf("%d", &m);
    for (int i = 0; i < m; i++) {
        int t1, t2;
        scanf("%d %d", &t1, &t2);
        set<int> &s1 = sets[t1-1], &s2 = sets[t2-1];
        int cnt = 0;
        for (auto num : s1) {
            if (s2.find(num) != s2.end()) cnt++;
        }
        printf("%.1lf%%\n", 100.0 * cnt / (s1.size() + s2.size() - cnt));
    }
    return 0;
}

