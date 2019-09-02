/*
 * referece:
 *  https://www.hdvsyu.com/posts/1229/
 */
#include <iostream>
#include <vector>
#include <climits>
#include <cstdlib>
#include <cmath>
using namespace std;
const int MAX_N = 501;
const int INF = INT_MAX;
int Cmax, N, Sp, M;
vector<int> stations(MAX_N);
vector<vector<int>> weights(MAX_N, vector<int>(MAX_N, INF));
vector<bool> visited(MAX_N, false);
vector<int> path, t_path;
int shortest = INF, sent = INF, back = INF;
void dfs(int cur, int t_len, int t_sent, int t_back) {
    if (cur == Sp) {
        if (t_len < shortest) {
            shortest = t_len;
            sent = t_sent;
            back = t_back;
            path = t_path;
        } else if (t_len == shortest) {
            if (t_sent < sent) {
                sent = t_sent;
                back = t_back;
                path = t_path;
            } else if (t_sent == sent) {
                if (t_back < back) {
                    back = t_back;
                    path = t_path;
                }
            }
        }
    } else {
        for (int i = 1; i <= N; i++) {
            if (visited[i] == false && weights[cur][i] != INF) {
                visited[i] = true;
                t_path.push_back(i);
                if (stations[i] <= 0) {
                    if (abs(stations[i]) <= t_back) {
                        dfs(i, t_len + weights[cur][i],
                                t_sent, t_back - abs(stations[i]));
                    } else {
                        dfs(i, t_len + weights[cur][i],
                                t_sent + abs(stations[i]) - t_back, 0);
                    }
                } else {
                    dfs(i, t_len + weights[cur][i],
                            t_sent, t_back + stations[i]);
                }
                visited[i] = false;
                t_path.pop_back();
            }
        }
    }
}
int main() {
    cin >> Cmax >> N >> Sp >> M;
    for (int i = 1; i <= N; i++) {
        cin >> stations[i];
        stations[i] -= Cmax / 2;
    }
    for (int i = 0; i < M; i++) {
        int r1, r2, w;
        cin >> r1 >> r2 >> w;
        weights[r1][r2] = weights[r2][r1] = w;
    }
    dfs(0, 0, 0, 0);
    cout << sent << " 0";
    for (auto &p : path) {
        cout << "->" << p;
    }
    cout << " " << back << endl;
    return 0;
}
