/*
 * Reference:
 *  https://www.xzy1996.com/post/72cdbcb3.html
 * The meaning of quadratic probing is use a step to find next prossible position...
 * fist step is 0 * 0, then 1 * 1, then 2 * 2...
 *
 */
#include <iostream>
#include <vector>
using namespace std;
bool is_prime(int num) {
    if (num == 1) return false;
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) return false;
    }
    return true;
}
int main() {
    int msize, n, t;
    cin >> msize >> n;
    while (!is_prime(msize)) { msize++; }
    vector<bool> table(msize, false);
    for (int i = 0; i < n; i++) {
        cin >> t;
        int step = 0;
        int pos = t % msize;
        while (pos < msize && table[pos] && step < msize) {
            pos = (t + step * step) % msize;
            step++;
        }
        if (i != 0) cout << " ";
        if (!table[pos]) {
            table[pos] = true;
            cout << pos;
        } else { cout << "-"; }
    }
    return 0;
}

