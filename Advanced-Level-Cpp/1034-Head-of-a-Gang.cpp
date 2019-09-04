#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <map>
using namespace std;
const int MAX_N = 2010;
int n, k, id = 0;
unordered_map<int, string> names;
unordered_map<string, int> ids;
vector<bool> visited(MAX_N, false);
vector<vector<int>> graph(MAX_N, vector<int>(MAX_N, 0));
vector<int> weights(MAX_N, 0);
map<string, int> ans;
int allocOrGetId(string name) {
    if (ids.find(name) == ids.end()) {
        names[id] = name;
        ids[name] = id;
        id++;
    }
    return ids[name];
}
void dfs(int c, int &head, int &mem_num, int &total_weight) {
    visited[c] = true;
    mem_num++;
    if (weights[c] > weights[head]) {
        head = c;
    }
    for (int i = 0; i < id; i++) {
        if (graph[c][i] > 0) {
            total_weight += graph[c][i];
            graph[c][i] = graph[i][c] = 0;
            if (!visited[i]) {
                dfs(i, head, mem_num, total_weight);
            }
        }
    }
}
int main() {
    cin >> n >> k;   
    for (int i = 0; i < n; i++) {
        string n1, n2;
        int w;
        cin >> n1 >> n2 >> w;
        int id1 = allocOrGetId(n1);
        int id2 = allocOrGetId(n2);
        graph[id1][id2] += w;
        graph[id2][id1] += w;
        weights[id1] += w;
        weights[id2] += w;
    }
    for (int i = 0; i < id; i++) {
        if (!visited[i]) {
            int head = i, mem_num = 0, total_weight = 0;
            dfs(i, head, mem_num, total_weight);
            if (mem_num > 2 && total_weight > k) {
                ans[names[head]] = mem_num;
            }
        }
    }
    cout << ans.size() << endl;
    for (auto &a : ans) {
        cout << a.first << " " << a.second << endl;
    }
    return 0;
}
