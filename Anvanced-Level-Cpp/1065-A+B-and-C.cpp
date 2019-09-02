/*
 * Reference:
 *  http://justin-yu.me/blog/2019/03/06/PAT-A-1065/
 *
 * First, I want to implement big number add and compare, than I see the refeence.
 * Since long long range is [2^-63, 2^63], we just need to consider whether a + b will
 * overflow.
 *
 * when a = 1l<<63 and b = 1l<<63, a + b will be 0.
 *
 */
#include <iostream>
#include <vector>
#include <string>
using namespace std;
int main() {
    int t;
    long long a, b, c, sum;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        cin >> a >> b >> c;
        sum = a + b;
        cout << "Case #" << i << ": ";
        if (a > 0 && b > 0 && sum < 0) cout << "true"; // positive overflow
        else if (a < 0 && b < 0 && sum >= 0) cout << "false"; // negative overflow
        else if (sum > c) cout << "true";
        else cout << "false";
        cout << "\n";
    }
    return 0;
}

