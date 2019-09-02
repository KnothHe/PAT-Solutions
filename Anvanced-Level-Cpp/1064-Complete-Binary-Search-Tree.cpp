/*
 * Reference:
 *  https://www.twblogs.net/a/5c2635d9bd9eee16b4a80acb
 *
 * When map a tree to an array:
 *
 * If the node i of the complete binary tree is numbered from 0,
 * then the left child is 2 * i + 1 and the right child is 2 * i + 2. [in this case]
 *
 * If the node i of the complete binary tree is numbered from 1,
 * then the left child is 2 * i and the right child is 2 * i + 1.
 *
 * while the binary search tree has the in-order traversal ascending,
 * so only the input sequence needs to be sorted in ascending order.
 * Then, the inorder traversal of the complete binary tree,
 * fill in the corresponding elements. [From reference]
 *
 */
#include <algorithm>
#include <vector>
#include <cstdio>
using namespace std;
vector<int> inorder;
vector<int> tree;
int n, index = 0;
void buildTree(int root) {
    if (root >= n) return;
    buildTree(root * 2 + 1);
    tree[root] = inorder[index++];
    buildTree(root * 2 + 2);
}
int main() {
    scanf("%d", &n);
    inorder.resize(n);
    tree.resize(n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &inorder[i]);
    }
    sort(inorder.begin(), inorder.end());
    buildTree(0);
    printf("%d", tree[0]);
    for (int i = 1; i < n; i++) {
        printf(" %d", tree[i]);
    }
    return 0;
}

