#include <iostream>
#include <set>
#include <string>
using namespace std;
int main() {
    string s1, s2, ans;
    getline(cin, s1);
    getline(cin, s2);
    set<char> chs(s2.begin(), s2.end());
    for (const auto ch : s1) {
        if (chs.find(ch) == chs.end()) ans.append(1, ch);
    }
    cout << ans << endl;
    return 0;
}
