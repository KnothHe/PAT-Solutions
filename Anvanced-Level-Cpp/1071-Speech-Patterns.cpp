#include <algorithm>
#include <iostream>
#include <map>
#include <cctype>
#include <string>
using namespace std;
int main() {
    string str, tstr;
    getline(cin, str);
    map<string, int> ma;
    for (int i = 0; i < str.size(); i++) {
        char ch = str[i];
        if (!isalnum(ch)) {
            if (!tstr.empty()) {
                ma[tstr]++;
                tstr.clear();
            }
        } else {
            tstr.append(1, tolower(ch));
        }
    }
    if (!tstr.empty()) ma[tstr]++;
    auto min_ele = min_element(ma.begin(), ma.end(), [](auto &lhs, auto &rhs) {
            return lhs.second != rhs.second ? lhs.second > rhs.second :
                lhs.first < rhs.first;
            });
    cout << min_ele->first << " " << min_ele->second << endl;
    return 0;
}

