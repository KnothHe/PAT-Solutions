/*
 * Just dfs.
 * Use greater<vector<int>>() as comparison function.
 *
 */
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
struct Node {
    int weight;
    vector<int> children;
};
int n, m, s;
vector<vector<int>> ans;
vector<int> path;
void dfs(int cur_node, int cur_weight, vector<Node> &nodes) {
    if (cur_weight >= s) {
        if (cur_weight == s && 
                nodes[cur_node].children.empty()) ans.push_back(path);
        return;
    }
    for (auto &node : nodes[cur_node].children) {
        cur_weight += nodes[node].weight;
        path.push_back(nodes[node].weight);
        dfs(node, cur_weight, nodes);
        path.pop_back();
        cur_weight -= nodes[node].weight;
    }
}
int main() {
    cin >> n >> m >> s;
    vector<Node> nodes(n);
    for (int i = 0; i < n; i++) {
        cin >> nodes[i].weight;
    }
    for (int i = 0; i < m; i++) {
        int id, c, child;
        cin >> id >> c;
        for (int i = 0; i < c; i++) {
            cin >> child;
            nodes[id].children.push_back(child);
        }
    }
    path.push_back(nodes[0].weight);
    dfs(0, nodes[0].weight, nodes);
    sort(ans.begin(), ans.end(), greater<vector<int>>());
    for (auto &path : ans) {
        for (int i = 0; i < path.size(); i++) {
            if (i != 0) cout << " ";
            cout << path[i];
        }
        cout << endl;
    }
    return 0;
}
