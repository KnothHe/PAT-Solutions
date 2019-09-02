/*
 * Traversing in the order of the string orig, for each ch in orig,
 * if ch doesn't appeared and is not in string type, output this ch.
 *
 */
#include <iostream>
#include <string>
#include <cctype>
using namespace std;
int main() {
    string orig, type, rs;
    cin >> orig >> type;
    for (char &c : type) { c = toupper(c); }
    for (char c : orig) {
        char ch = toupper(c);
        if (rs.find(ch) == string::npos && type.find(ch) == string::npos) {
            rs.append(1, ch);
        }
    }
    cout << rs;
    return 0;
}

