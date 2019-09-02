#include <iostream>
#include <vector>
using namespace std;
const int maxn = 1005;
int m, n;
vector<int> level(maxn), post;
bool max_heap(int root) {
    if (root >= n) return true;
    int left = 2 * root + 1, right = 2 * root + 2;
    if (left < n && level[root] < level[left]) return false;
    if (right < n && level[root] < level[right]) return false;
    return max_heap(left) && max_heap(right);
}
bool min_heap(int root) {
    if (root >= n) return true;
    int left = 2 * root + 1, right = 2 * root + 2;
    if (left < n && level[root] > level[left]) return false;
    if (right < n && level[root] > level[right]) return false;
    return min_heap(left) && min_heap(right);
}
void postorder(int root) {
    if (root >= n) return;
    postorder(2 * root + 1);
    postorder(2 * root + 2);
    post.push_back(level[root]);
}
int main() {
    cin >> m >> n;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) { cin >> level[j]; }
        if (max_heap(0)) { cout << "Max Heap\n"; }
        else if (min_heap(0)) { cout << "Min Heap\n"; }
        else { cout << "Not Heap\n"; }
        post.clear();
        postorder(0);
        for (int j = 0; j < n; j++) {
            if (j != 0) { cout << " "; }
            cout << post[j];
        }
        cout << "\n";
    }
    return 0;
}

