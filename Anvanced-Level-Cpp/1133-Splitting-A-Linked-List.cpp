#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
const int maxn = 1000005;
struct Node {
    int order, addr, val, next, valid;
};
int main() {
    int head, n, k;
    cin >> head >> n >> k;
    vector<Node> ns(maxn);
    for (int i = 0; i < ns.size(); i++) { ns[i].valid = -1; }
    for (int i = 0; i < n; i++) {
        int addr, val, next;
        cin >> addr >> val >> next;
        ns[addr].addr = addr;
        ns[addr].val = val;
        ns[addr].next = next;
    }
    int cur = head;
    int cnt = 0;
    while (cur != -1) {
        ns[cur].valid = 1;
        if (ns[cur].val < 0) { ns[cur].order = cnt - 2 * maxn; }
        else if (ns[cur].val <= k) { ns[cur].order = cnt - maxn; }
        else { ns[cur].order = cnt; }
        cur = ns[cur].next;
        cnt++;
    }
    sort(ns.begin(), ns.end(), [](auto &lhs, auto &rhs) {
            return lhs.valid != rhs.valid ? lhs.valid > rhs.valid :
            lhs.order < rhs.order;
            });
    for (int i = 0; i < ns.size() && ns[i].valid == 1; i++) {
        printf("%05d %d ", ns[i].addr, ns[i].val);
        if (i == cnt - 1) { printf("-1\n"); }
        else { printf("%05d\n", ns[i+1].addr); }
    }
    return 0;
}

