#include <iostream>
#include <vector>
#include <string>
using namespace std;
const int maxn = 25;
struct Node {
    string val;
    int left, right;
};
int n, root;
Node nodes[maxn];
string infix;
void infix_order(int root) {
    if (root == -1) { return; }
    if (nodes[root].left != -1 || nodes[root].right != -1) infix.append(1, '(');
    infix_order(nodes[root].left);
    infix.append(nodes[root].val);
    infix_order(nodes[root].right);
    if (nodes[root].left != -1 || nodes[root].right != -1) infix.append(1, ')');
}
int main() {
    cin >> n;
    vector<bool> roots(n+1, true);
    for (int i = 1; i <= n; i++) {
        cin >> nodes[i].val >> nodes[i].left >> nodes[i].right;
        if (nodes[i].left != -1) roots[nodes[i].left] = false;
        if (nodes[i].right != -1) roots[nodes[i].right] = false;
    }
    for (root = 1; root <= n; root++) { if (roots[root]) { break; } }
    infix_order(root);
    if (!infix.empty() && infix[0] == '(') { infix = infix.substr(1, infix.size()- 2); } 
    cout << infix << "\n";
    return 0;
}

