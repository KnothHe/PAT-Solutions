/*
 * Reference:
 *  https://www.liuchuo.net/archives/2168
 *
 * The sequence of push to stack is pre travel, and the sequence of pop from stack is
 * inorder travel. Then this question just convert to generating postorder travel
 * with preorder and inorder.
 *
 */
#include <iostream>
#include <vector>
#include <stack>
#include <string>
using namespace std;
vector<int> pre, in, post;
stack<int> st;
void postorder(int root, int ibeg, int iend) {
    if (ibeg > iend) return;
    int idx = ibeg;
    while (idx <= iend && in[idx] != pre[root]) { idx++; }
    postorder(root + 1, ibeg, idx - 1);
    postorder(root + 1 + idx - ibeg, idx + 1, iend);
    post.push_back(pre[root]);
}
int main() {
    int n, t;
    cin >> n;
    string op;
    for (int i = 1; i <= 2*n; i++) {
        cin >> op;
        switch (op[1]) {
            case 'u' :
                cin >> t;
                st.push(t);
                pre.push_back(t);
                break;
            case 'o' :
                t = st.top();
                in.push_back(t);
                st.pop();
                break;
        }
    }
    postorder(0, 0, in.size() - 1);
    if (!post.empty()) cout << post[0];
    for (int i = 1; i < post.size(); i++) { cout << " " << post[i]; }
    return 0;
}

