#include <iostream>
#include <vector>
using namespace std;
vector<int> in, pre, post;
bool unique = true;
void to_inorder(int prel, int prer, int postl, int postr) {
    if (prel > prer) { return; }
    int idx, cnt = 0;
    for (idx = postl; idx < postr; idx++) {
        cnt++;
        if (post[idx] == pre[prel+1]) break;
    }
    if (idx == postr-1) { unique = false; }
    to_inorder(prel+1, prel+cnt, postl, idx);
    in.push_back(pre[prel]);
    to_inorder(prel+cnt+1, prer, idx+1, postr-1);
}
int main() {
    int n;
    cin >> n;
    pre.resize(n);
    post.resize(n);
    for (int i = 0; i < n; i++) { cin >> pre[i]; }
    for (int i = 0; i < n; i++) { cin >> post[i]; }
    to_inorder(0, n-1, 0, n-1);
    cout << (unique ? "Yes\n" : "No\n");
    if (n > 0) { cout << in[0]; }
    for (int i = 1; i < n; i++) {
        cout << " " << in[i];
    }
    cout << "\n";
    return 0;
}

