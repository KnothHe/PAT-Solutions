#include <iostream>
#include <vector>
using namespace std;
const int maxn = 1000005;
struct Node {
    int addr, val, next;
};
Node ns[maxn];
int main() {
    int head, n, k;
    cin >> head >> n >> k;
    for (int i = 0; i < n; i++) {
        int addr, val, next;
        cin >> addr >> val >> next;
        ns[addr].addr = addr;
        ns[addr].val = val;
        ns[addr].next = next;
    }
    vector<Node> ts, rs;
    int cur = head;
    while (cur != -1) {
        ts.push_back(ns[cur]);
        cur = ns[cur].next;
    }
    for (int i = 0; i < ts.size(); i++) {
        if (ts[i].val < 0) rs.push_back(ts[i]);
    }
    for (int i = 0; i < ts.size(); i++) {
        if (ts[i].val <= k && ts[i].val >= 0) rs.push_back(ts[i]);
    }
    for (int i = 0; i < ts.size(); i++) {
        if (ts[i].val > k) rs.push_back(ts[i]);
    }
    for (int i = 0; i < rs.size(); i++) {
        printf("%05d %d ", rs[i].addr, rs[i].val);
        if (i == rs.size() - 1) { printf("-1\n"); }
        else { printf("%05d\n", rs[i+1].addr); }
    }
    return 0;
}

