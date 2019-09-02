/*
 * If using dfs (recursive), the last two test cases will be segment fault.
 * I though it is stack overflow.
 *
 * So just bfs(or stack-based dfs).
 *
 */
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int m, n, l, t, tp;
struct Pos {
    int x, y, z;
};
vector<vector<vector<bool>>> gp;
int dx[6] = {1, -1, 0, 0, 0, 0};
int dy[6] = {0, 0, 1, -1, 0, 0};
int dz[6] = {0, 0, 0, 0, 1, -1};
bool judge(int i, int j, int k) {
    if (i < 0 || i >= l || j < 0 || j >= m || k < 0 || k >= n) return false;
    return gp[i][j][k];
}
int bfs(int x, int y, int z) {
    int cnt = 1;
    queue<Pos> que;
    que.push({x, y, z});
    gp[x][y][z] = false;
    while (!que.empty()) {
        Pos cpos = que.front();
        que.pop();
        for (int i = 0; i < 6; i++) {
            int tx = cpos.x + dx[i];
            int ty = cpos.y + dy[i];
            int tz = cpos.z + dz[i];
            if (judge(tx, ty, tz)) {
                que.push({tx, ty, tz});
                gp[tx][ty][tz] = false;
                cnt++;
            }
        }
    }
    return cnt;
}
int main() {
    cin >> m >> n >> l >> t;
    gp.resize(l, vector<vector<bool>>(m, vector<bool>(n, false)));
    for (int i = 0; i < l; i++)
        for (int j = 0; j < m; j++)
            for (int k = 0; k < n; k++) {
                cin >> tp;
                if (tp == 1) gp[i][j][k] = true;
            }
    int cnt = 0;
    for (int i = 0; i < l; i++)
        for (int j = 0; j < m; j++)
            for (int k = 0; k < n; k++)
                if (gp[i][j][k]) {
                    int tcnt = bfs(i, j, k);
                    if (tcnt >= t) cnt += tcnt;
                }
    cout << cnt;
    return 0;
}

