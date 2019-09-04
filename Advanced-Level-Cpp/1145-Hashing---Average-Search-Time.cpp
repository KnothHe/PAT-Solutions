#include <iostream>
#include <vector>
using namespace std;
int msize, n, m, t;
vector<int> table;
bool is_prime(int x) {
    if (x <= 1) { return false; }
    for (int i = 2; i * i <= x; i++) {
        if (x % i == 0) { return false; }
    }
    return true;
}
int main() {
    cin >> msize >> n >> m;
    while (!is_prime(msize)) { msize++; }
    table.resize(msize, -1);
    for (int i = 0; i < n; i++) {
        cin >> t;
        int step = 0, pos = t % msize;
        while (pos < msize && step <= msize && table[pos] != -1) {
            pos = (t + step * step) % msize;
            step++;
        }
        if (table[pos] != -1) { printf("%d cannot be inserted.\n", t); }
        else {
            table[pos] = t;
        }
    }
    int rs = 0;
    for (int i = 0; i < m; i++) {
        cin >> t;
        int step = 0, pos = t % msize;
        while (pos < msize && step <= msize) {
            rs++;
            pos = (t + step * step) % msize;
            if (table[pos] == -1 || table[pos] == t) { break; }
            step++;
        }
    }
    printf("%.1lf\n", (double) rs / m);
    return 0;
}

