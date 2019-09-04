#include <algorithm>
#include <iostream>
#include <string>
using namespace std;
bool is_palid(string s) {
    int l = 0, r = s.size()-1;
    while (l < r) {
        if (s[l] != s[r]) return false;
        l++; r--;
    }
    return true;
}
string add(string s1, string s2) {
    reverse(s1.begin(), s1.end());
    reverse(s2.begin(), s2.end());
    int len1 = s1.size(), len2 = s2.size(), c = 0;
    string rs;
    for (int i = 0; i < len1 || i < len2; i++) {
        int a = i < len1 ? s1[i] - '0' : 0;
        int b = i < len2 ? s2[i] - '0' : 0;
        int r = a + b + c;
        rs.append(1, r % 10 + '0');
        c = r / 10;
    }
    if (c != 0) rs.append(1, '1');
    reverse(rs.begin(), rs.end());
    return rs;
}

int main() {
    int cnt;
    string n;
    cin >> n;
    bool flag = false;
    for (cnt = 0; cnt < 10; cnt++) {
        if (is_palid(n)) { flag = true; break; }
        string s(n);
        reverse(s.begin(), s.end());
        string r = add(s, n);
        cout << n << " + " << s << " = " << r << "\n";
        n = r;
    }
    if (flag) { cout << n << " is a palindromic number.\n"; }
    else { cout << "Not found in 10 iterations.\n"; }
    return 0;
}

