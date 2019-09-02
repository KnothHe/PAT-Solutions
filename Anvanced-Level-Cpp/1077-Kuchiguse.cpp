#include <iostream>
#include <string>
using namespace std;
int last_common_pos_of_first(string a, string b) { // a shorter than b
    int ia = a.size() - 1, ib = b.size() - 1;
    while (ia >= 0) {
        if (a[ia] != b[ib]) break;
        ia--; ib--;
    }
    return ia + 1;
}
int main() {
    int n;
    scanf("%d\n", &n);
    string ip, rs; // input, result string
    bool valid = true;
    for (int i = 0; i < n; i++) {
        getline(cin, ip);
        if (rs.empty()) rs = ip;
        else {
            if (rs.size() > ip.size()) swap(ip, rs); // rs shorter than ip
            int lcpos = last_common_pos_of_first(rs, ip);
            if (lcpos <= rs.size() - 1) rs = rs.substr(lcpos);
            else valid = false;
        }
        if (!valid) break;
    }
    if (valid) cout << rs;
    else cout << "nai";
    return 0;
}

