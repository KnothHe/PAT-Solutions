/*
 * Travesing the array, if current character is 'A', the total count must add
 * left count of 'P' * right count of 'T'.
 *
 */
#include <iostream>
#include <vector>
#include <string>
using namespace std;
int main() {
    string inp;
    cin >> inp;
    vector<int> ps(inp.size(), 0), ts(inp.size(), 0);
    int pcnt = 0, tcnt = 0, lasta = 0;
    int cnt = 0;
    for (int i = 0; i < inp.size(); i++) {
        char c = inp[i];
        if (c == 'A') {
            ps[i] = ps[lasta] + pcnt;
            pcnt = 0;
            lasta = i;
        } else if (c == 'P') { pcnt++; }
    }
    lasta = 0;
    for (int i = inp.size() - 1; i >= 0; i--) {
        char c = inp[i];
        if (c == 'A') {
            ts[i] = ts[lasta] + tcnt;
            tcnt = 0;
            lasta = i;
            cnt = (cnt + ts[i] * ps[i]) % 1000000007;
        } else if (c == 'T') { tcnt++; }
    }
    cout << cnt;
    return 0;
}

