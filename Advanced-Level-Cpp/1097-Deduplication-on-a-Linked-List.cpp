/*
 * Use set occu to record if the absolute value of this node's key has occured.
 * if has occured, add this node to rs arrary.
 * if not, add this node to dups array.
 *
 */
#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <cmath>
using namespace std;
struct Node {
    int addr, key, next;
};
void print_nodes(vector<Node> &nodes) {
    if (nodes.empty()) return;
    for (int i = 0; i < nodes.size() - 1; i++) {
        printf("%05d %d %05d\n", nodes[i].addr, nodes[i].key, nodes[i + 1].addr);
    }
    printf("%05d %d -1\n", nodes.back().addr, nodes.back().key);
}
int main() {
    int root, n;
    cin >> root >> n;
    map<int, Node> nodes;
    for (int i = 0; i < n; i++) {
        int addr, key, next;
        cin >> addr >> key >> next;
        nodes[addr] = {addr, key, next};
    }
    int cur = root;
    set<int> occu;
    vector<Node> dups;
    vector<Node> rs;
    while (cur != -1) {
        int key = abs(nodes[cur].key);
        if (occu.find(key) == occu.end()) {
            occu.insert(key);
            rs.push_back(nodes[cur]);
        } else {
            dups.push_back(nodes[cur]);
        }
        cur = nodes[cur].next;
    }
    print_nodes(rs);
    print_nodes(dups);
    return 0;
}

