/*
 * Sort
 *
 * when there is no node in list, the head of sorted list is -1, still need to output.
 *
 */
#include <algorithm>
#include <iostream>
#include <vector>
#include <map>
using namespace std;
struct Node {
    int addr, key, next;
} node;
int main() {
    int n, head;
    cin >> n >> head;
    map<int, Node> node_map;
    for (int i = 0; i < n; i++) {
        cin >> node.addr >> node.key >> node.next;
        node_map[node.addr] = node;
    }
    int cur = head;
    vector<Node> nodes;
    while (cur != -1 && !node_map.empty()) {
        nodes.push_back(node_map[cur]);
        cur = node_map[cur].next;
    }
    sort(nodes.begin(), nodes.end(), [](auto &lhs, auto &rhs){
            return lhs.key < rhs.key;
            });
    printf("%zu ", nodes.size());
    if (!nodes.empty()) printf("%05d\n", nodes.front().addr);
    else printf("-1\n"); // !!! NOTE !!!
    for (int i = 0; i < nodes.size(); i++) {
        printf("%05d %d ", nodes[i].addr, nodes[i].key);
        if (i + 1 < nodes.size()) printf("%05d\n", nodes[i+1].addr);
        else printf("-1\n");
    }
    return 0;
}

