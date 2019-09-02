#include <algorithm>
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
int main() {
    int n, mm, nn;
    cin >> n;
    for (nn = (int)sqrt(n); nn >= 1; nn--) {
        if (n % nn == 0) {
            mm = n / nn;
            break;
        }
    }
    vector<int> ns(n);
    vector<vector<int>> rs(mm, vector<int>(nn));
    for (int i = 0; i < n; i++) { cin >> ns[i]; }
    sort(ns.begin(), ns.end(), greater<int>());
    int top = 0, left = 0, right = nn - 1, bottom = mm - 1;
    for (int i = 0; i < n;) {
        for (int j = left; j <= right && i < n; j++) { rs[top][j] = ns[i++]; }
        for (int j = top+1; j <= bottom && i < n; j++) { rs[j][right] = ns[i++]; }
        for (int j = right-1; j >= left && i < n; j--) { rs[bottom][j] = ns[i++]; }
        for (int j = bottom-1; j >= top+1 && i < n; j--) { rs[j][left] = ns[i++]; }
        left++; top++; right--; bottom--;
    }
    for (int i = 0; i < mm; i++) {
        if (!rs[i].empty()) cout << rs[i][0];
        for (int j = 1; j < nn; j++) {
            cout << " " << rs[i][j];
        }
        cout << "\n";
    }
    return 0;
}

