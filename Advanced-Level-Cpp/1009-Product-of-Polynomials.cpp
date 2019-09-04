#include <iostream>
#include <vector>
using namespace std;
const int maxn = 1005;
vector<double> p1(maxn, 0), p2(maxn, 0), p(maxn * maxn, 0);
int main() {
    int k, n, size = 0;
    double a;
    cin >> k;
    for (int i = 0; i < k; i++) { cin >> n >> a; p1[n] = a; }
    cin >> k;
    for (int i = 0; i < k; i++) { cin >> n >> a; p2[n] = a; }
    for (int i = 0; i < maxn; i++) {
        for (int j = 0; j < maxn; j++) {
            p[i + j] += p1[i] * p2[j];
        }
    }
    for (int i = 0; i < maxn * maxn; i++) {
        if (p[i] != 0) { size++; }
    }
    printf("%d", size);
    for (int i = maxn * maxn - 1; i >= 0; i--) {
        if (p[i] != 0) { printf(" %d %.1lf", i, p[i]); }
    }
    return 0;
}

