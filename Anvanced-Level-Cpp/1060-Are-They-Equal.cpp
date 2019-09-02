/*
 * nz index of first non zero element                 the number of significant digits
 * p index of '.'                                                   |
 * cnt number of significant bit                                   ----
 *                                                                 |  |
 * if nz == s.size(), then this nubmer must be 0, we just return 0.0..0*10^0.
 *
 * we just append origial bit of number to result string.
 * the weight of this number is:
 *  p - nz, if p >= nz;
 *  p - nz + 1, if p < nz.
 * when the significant bits of original number is not enough, append 0.
 *
 */
#include <iostream>
#include <string>
using namespace std;
string format(string &s, int n) {
    int nz = 0, p = 0, cnt = 0;
    string rs("0.");
    while (nz < s.size() && (s[nz] == '0' || s[nz] == '.'))  nz++;
    while (p < s.size() && s[p] != '.') p++;
    if (nz == s.size()) {
        rs.append(n, '0').append("*10^0");
        return rs;
    }
    for (int i = nz; i < s.size(); i++) {
        if (i == p) continue;
        if (cnt < n) rs.append(1, s[i]);
        cnt++;
    }
    while (cnt < n) {
        rs.append("0");
        cnt++;
    }
    int w = p - nz < 0 ? p - nz + 1 : p - nz;
    rs.append("*10^" + to_string(w));
    return rs;
}
int main() {
    int n;
    string a, b;
    cin >> n >> a >> b;
    string ra = format(a, n);
    string rb = format(b, n);
    if (ra == rb) {
        cout << "YES " << ra;
    } else {
        cout << "NO " << ra << " " << rb;
    }
    return 0;
}

