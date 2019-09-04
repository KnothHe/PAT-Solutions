#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;
int main() {
    string owner, eva;
    cin >> owner >> eva;
    map<char, int> o, e;
    for (int i = '0'; i <= '9'; i++) { o[i] = 0; e[i] = 0; }
    for (int i = 'a'; i <= 'z'; i++) { o[i] = 0; e[i] = 0; }
    for (int i = 'A'; i <= 'Z'; i++) { o[i] = 0; e[i] = 0; }
    for (char c : owner) { o[c]++; }
    for (char c : eva) { e[c]++; }
    int missing = 0, extra = 0;
    bool has_all = true;
    for (auto &c : o) {
        int df = o[c.first] - e[c.first];
        if (df >= 0) extra += df;
        else {
            has_all = false;
            missing += -df;
        }
    }
    if (has_all) { cout << "Yes " << extra; }
    else { cout << "No " << missing; }
    return 0;
}

