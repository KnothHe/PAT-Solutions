#include <iostream>
#include <vector>
using namespace std;
const int maxn = 1005;
int m, n;
vector<int> level(maxn), post;
bool max_heap() {
    for (int i = 0; i < n; i++) {
        int left = 2 * i + 1, right = 2 * i + 2;
        if (left < n && level[i] < level[left]) return false;
        if (right < n && level[i] < level[right]) return false;
    }
    return true;
}
bool min_heap() {
    for (int i = 0; i < n; i++) {
        int left = 2 * i + 1, right = 2 * i + 2;
        if (left < n && level[i] > level[left]) return false;
        if (right < n && level[i] > level[right]) return false;
    }
    return true;
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
        if (max_heap()) { cout << "Max Heap\n"; }
        else if (min_heap()) { cout << "Min Heap\n"; }
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

