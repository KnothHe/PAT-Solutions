#include <iostream>
#include <string>
using namespace std;
int main() {
    string a;
    cin >> a;
    bool is_neg = a[0] == '-'; // is negative ?
    int epos = a.find('E'); // position of 'E'
    string num = a[1] + a.substr(3, epos - 3); // pure number
    int exp = stoi(a.substr(epos + 1)); // exponent
    string rs; // result
    if (exp < 0) {
        rs.append("0.").append(-exp-1, '0').append(num);
    } else if (exp > 0) {
        int frac_len = num.size() - 1;
        if (frac_len <= exp) rs.append(num).append(exp - frac_len, '0');
        else rs.append(num).insert(exp + 1, 1, '.');
    } else {
        rs.append(num).insert(1, 1, '.');
    }
    if (is_neg) cout << "-";
    cout << rs << endl;
    return 0;
}

