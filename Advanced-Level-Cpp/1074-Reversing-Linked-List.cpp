/*
 * Similar problem:
 *  https://leetcode.com/problems/reverse-nodes-in-k-group/
 * My solution refer discussion:
 *  https://github.com/KnothHe/Problems/blob/master/LeetCode/java/25.reverse-nodes-in-k-group.java
 *
 */
#include <iostream>
#include <vector>
#include <map>
using namespace std;
struct Node {
    int val, next;
} node;
map<int, Node> nodes;
int reverse_k(int head, int k) {
    int cnt = 0, cur = head;
    while (cnt < k && cur != -1) {
        cnt++;
        cur = nodes[cur].next;
    }
    if (cnt == k) {
        cur = reverse_k(cur, k);
        for (int i = 0; i < k; i++) {
            int t = nodes[head].next;
            nodes[head].next = cur;
            cur = head;
            head = t;
        }
        head = cur;
    }
    return head;
}
int main() {
    int n, k, addr, head;
    cin >> head >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> addr >> node.val >> node.next;
        nodes[addr] = node;
    }
    head = reverse_k(head, k);
    while (head != -1) {
        int next = nodes[head].next;
        printf("%05d %d ", head, nodes[head].val);
        if (next == -1) printf("-1");
        else printf("%05d\n", next);
        head = next;
    }
    return 0;
}

