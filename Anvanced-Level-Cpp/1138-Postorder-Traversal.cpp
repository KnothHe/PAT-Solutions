#include <iostream>
#include <vector>
using namespace std;
vector<int> in, pre, post;
void to_postorder(int inl, int inr, int prel) {
    if (inl > inr || !post.empty()) { return; }
    int idx;
    for (idx = inl; idx <= inr; idx++) { if (in[idx] == pre[prel]) { break; } }
    to_postorder(inl, idx - 1, prel + 1);
    to_postorder(idx + 1, inr, prel + idx - inl);
    post.push_back(pre[prel]);
}
int main() {
    int n;
    scanf("%d", &n);
    in.resize(n);
    pre.resize(n);
    for (int i = 0; i < n; i++) {  scanf("%d", &pre[i]); }
    for (int i = 0; i < n; i++) {  scanf("%d", &in[i]); }
    to_postorder(0, n-1, 0);
    cout << post[0] << "\n";
    return 0;
}

