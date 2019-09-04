/*
 * Because the maximum factor of a number does not exceed its square root,
 * we just need iterate to sqrt(n).
 *
 * For each number bewteen 2 and sqrt(n), get max len that it can get.
 *
 */
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
int main() {
    int n;
    cin >> n;
    int len = 0, nbeg = 0, maxn = sqrt(n);
    for (int i = 2; i <= maxn; i++) {
        int prod = 1, j;
        for (j = i; j <= maxn; j++) {
            prod *= j;
            if (n % prod != 0) { break; }
        }
        if (j - i > len) {
            nbeg = i;
            len = j - i;
        }
    }
    if (nbeg == 0) {
        cout << 1 << "\n" << n;
    } else {
        cout << len << "\n" << nbeg;
        for (int i = nbeg + 1; i < nbeg + len; i++) { cout << "*" << i; }
    }
    return 0;
}

