/*
 * Simulation
 * 
 * For Heap Sort, each node swap with its larger child.
 * When it's child index exceed end, just swap this node with end.
 *
 */
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
int main() {
    int n;
    cin >> n;
    vector<int> ns(n), pa(n);
    for (int i = 0; i < n; i++) { cin >> ns[i]; }
    for (int i = 0; i < n; i++) { cin >> pa[i]; }
    int idx = 1;
    while (idx < n && pa[idx - 1] <= pa[idx]) { idx++; }
    while (idx < n && ns[idx] == pa[idx]) { idx++; }
    if (idx == n) {
        cout << "Insertion Sort\n";
        idx = 1;
        while (idx < n && pa[idx - 1] <= pa[idx]) { idx++; }
        sort(pa.begin(), pa.begin() + idx + 1);
    } else {
        cout << "Heap Sort\n";
        int end = n - 1;
        while (pa[end] >= pa[end-1]) { end--; }
        int it = 0;
        while (it < end) {
            int j = 2*it+1;
            if (2*it+2 <= end && pa[2*it+2] > pa[j]) j = 2*it+2;
            if (j > end) j = end;
            swap(pa[it], pa[j]);
            it = j;
        }
    }
    cout << pa[0];
    for (int i = 1; i < n; i++) { cout << " " << pa[i]; }
    return 0;
}

