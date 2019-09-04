#include <iostream>
#include <vector>
#include <utility>
using namespace std;
const int MAX_N = 505;
const int INF = 0x7fffffff;
int n, m, s, d;
vector<vector<pair<int, int>>> graph(MAX_N, vector<pair<int, int>>(MAX_N, { INF, INF }));
vector<int> path, t_path;
int g_dis = INF, g_cost = INF;
vector<bool> visited(MAX_N, false);
void dfs(int cur, int t_dis, int t_cost) {
    if (cur == d) {
        if (t_dis < g_dis) {
            g_dis = t_dis;
            g_cost = t_cost;
            path = t_path;
        } else if (t_dis == g_dis) {
            if (t_cost < g_cost) {
                g_cost = t_cost;
                path = t_path;
            }
        }
        return;
    }
    for (int i = 0; i < MAX_N; i++) {
        if (graph[cur][i].first != INF && !visited[i]) {
            t_path.push_back(i);
            visited[i] = true;
            dfs(i, t_dis + graph[cur][i].first, t_cost + graph[cur][i].second);
            visited[i] = false;
            t_path.pop_back();
        }
    }
}
int main() {
    cin >> n  >> m >> s >> d;
    for (int i = 0; i < m; i++) {
        int c1, c2, dis, cost;
        cin >> c1 >> c2 >> dis >> cost;
        graph[c1][c2] = graph[c2][c1] = { dis, cost };
    }
    visited[s] = true;
    t_path.push_back(s);
    dfs(s, 0, 0);
    for (auto &n : path) {
        cout << n << " ";
    }
    cout << g_dis << " " << g_cost;
    return 0;
}

