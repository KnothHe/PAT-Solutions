#include <iostream>
#include <vector>
using namespace std;
vector<int> level, ts;
int n, cnt = 0;
bool max_heap = true, min_heap = true;
void dfs(int root) {
    if (root >= n) {
        cnt++;
        if (cnt % 2 == 0) {
            for (int i = 0; i < ts.size(); i++) {
                if (i != 0) { cout << " "; }
                cout << ts[i];
            }
            cout << "\n";
        }
        return;
    }
    ts.push_back(level[root]);
    int left = 2 * root + 1, right = 2 * root + 2;
    if (left < n) {
        if (level[left] > level[root]) { max_heap = false; }
        if (level[left] < level[root]) { min_heap = false; }
    }
    if (right < n) {
        if (level[right] > level[root]) { max_heap = false; }
        if (level[right] < level[root]) { min_heap = false; }
    }
    dfs(right);
    dfs(left);
    ts.pop_back();
}
int main() {
    cin >> n;
    level.resize(n);
    for (int i = 0; i < n; i++) { cin >> level[i]; }
    dfs(0);
    if (max_heap) { cout << "Max Heap\n"; }
    else if (min_heap) { cout << "Min Heap\n"; }
    else { cout << "Not Heap\n"; }
    return 0;
}

