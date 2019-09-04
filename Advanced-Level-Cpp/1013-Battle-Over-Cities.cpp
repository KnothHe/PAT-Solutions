#include <iostream>
#include <vector>
using namespace std;
const int maxn = 1005;
vector<vector<int>> gp(maxn);
vector<bool> mark(maxn);
void dfs(int c)
{
    mark[c] = true;
    for (auto &nc : gp[c]) {
        if (!mark[nc]) {
            dfs(nc);
        }
    }
}
int main()
{
    int n, m, k, c1, c2, c, cnt;
    scanf("%d %d %d", &n, &m, &k);
    for (int i = 0; i < m; i++) {
        scanf("%d %d", &c1, &c2);
        gp[c1].push_back(c2);
        gp[c2].push_back(c1);
    }
    for (int i = 0; i < k; i++) {
        fill(mark.begin(), mark.end(), false);
        scanf("%d", &c);
        mark[c] = true;
        cnt = 0;
        for (int j = 1; j <= n; j++) {
            if (!mark[j]) {
                cnt++;
                dfs(j);
            }
        }
        printf("%d\n", cnt-1);
    }
    return 0;
}

