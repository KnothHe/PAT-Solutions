#include <algorithm>
#include <iostream>
#include <vector>
#include <climits>
using namespace std;
const int MAX_N = 10005;
vector<vector<int>> graph(MAX_N, vector<int>());
vector<bool> visited(MAX_N, false);
int N;
int components = 0;
vector<int> deeps(MAX_N, -1);
void dfs(int cur) {
    for (const auto &n : graph[cur]) {
        if (!visited[n]) {
            visited[n] = true;
            dfs(n);
        }
    }
}
void deepestOfRoot(int root, int cur, int deep) {
    for (const auto &n : graph[cur]) {
        if (!visited[n]) {
            visited[n] = true;
            deepestOfRoot(root, n, deep + 1);
        }
    }
    deeps[root] = max(deeps[root], deep);
}
int main() {
    cin >> N;
    for (int i = 0; i < N - 1; i++) {
        int n1, n2;
        cin >> n1 >> n2;
        graph[n1].push_back(n2); graph[n2].push_back(n1);
    }
    for (int i = 1; i <= N; i++) {
        if (!visited[i]) {
            visited[i] = true;
            components++;
            dfs(i);
        }
    }
    if (components != 1) {
        cout << "Error: " << components << " components" << endl;
    } else {
        for (int i = 1; i <= N; i++) {
            fill(visited.begin(), visited.end(), false);
            visited[i] = true;
            deepestOfRoot(i, i, 1);
        }
        int deepest = *max_element(deeps.begin(), deeps.end());
        vector<int> result;
        for (int i = 0; i < deeps.size(); i++) {
            if (deeps[i] == deepest) {
                result.push_back(i);
            }
        }
        for (const auto &n : result) {
            cout << n << endl;
        }
    }
    return 0;
}
