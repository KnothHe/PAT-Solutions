/*
 * Reference:
 *  https://www.liuchuo.net/archives/2329
 */
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
string s;
void add(string t) {
    int carry = 0;
    for (int i = 0; i < t.size(); i++) {
        s[i] += t[i] - '0' + carry;
        carry = 0;
        if (s[i] > '9') {
            s[i] -= 10;
            carry = 1;
        }
    }
    if (carry) s += '1';
    reverse(s.begin(), s.end());
}
int main() {
    int step, K;
    cin >> s >> K;
    for (step = 0; step < K; step++) {
        string t(s);
        reverse(t.begin(), t.end());
        if (t == s) break;
        add(t);
    }
    cout << s << '\n' << step << endl;
    return 0;
}
