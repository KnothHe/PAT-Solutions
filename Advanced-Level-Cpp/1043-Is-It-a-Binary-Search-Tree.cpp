/*
 * Reference:
 *  https://www.liuchuo.net/archives/2153
 *
 *  First, assume this bst is not a mirrored tree of bst, set is_mirror as false,
 *  use get_post function to get the postorder of the bst accroding preorder of the bst,
 *  if not, set is_mirror as true, still use get_post to get postorder of the bst.
 *
 *  how to get post of a bst accroding a pre order of this tree?
 *  we has these rules:
 *      1. all numbers of left tree must be less than the root.
 *      2. all numbers of right tree must be greater than or equal to the root.
 *  First travel from left to right to get all numbers less than the root, use l recorde the final position.
 *  Second travel from right to left to get all numbers greater than or equal to the root, use r record the final positon.
 *  If l - r is 1, than just recurse left tree and right tree.
 *  If l - r is not 1, then the tree must not a bst.
 */
#include <iostream>
#include <vector>
using namespace std;
vector<int> pre, post;
bool is_mirror = false;
void get_post(int root, int end) {
    int l = root + 1, r = end;
    if (!is_mirror) {
        while (l <= end && pre[l] < pre[root]) l++;
        while (r > root && pre[r] >= pre[root]) r--;
    } else {
        while (l <= end && pre[l] >= pre[root]) l++;
        while (r > root && pre[r] < pre[root]) r--;
    }
    if (l - r != 1) return;
    get_post(root + 1, l - 1);
    get_post(r + 1, end);
    post.push_back(pre[root]);
}
int main() {
    int n;
    cin >> n;
    pre.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> pre[i];
    }
    get_post(0, n - 1);
    if (post.size() != n) {
        is_mirror = true;
        post.clear();
        get_post(0, n - 1);
    }
    if (post.size() != n) {
        cout << "NO";
    } else {
        cout << "YES" << endl;
        for (int i = 0; i < n; i++) {
            if (i != 0) cout << " ";
            cout << post[i];
        }
    }
    return 0;
}
