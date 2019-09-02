#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <map>
using namespace std;
string D1[13] = {"tret", "jan", "feb", "mar", "apr", "may",
    "jun", "jly", "aug", "sep", "oct", "nov", "dec"};
string D2[13] = {"    ", "tam", "hel", "maa", "huh", "tou",
    "kes", "hei", "elo", "syy", "lok", "mer", "jou"};
int main() {
    int n;
    scanf("%d\n", &n);
    string inp, rs;
    map<string, int> getD1, getD2;
    for (int i = 0; i < 13; i++) {
        getD1[D1[i]] = i;
        getD2[D2[i]] = i;
    }
    for (int i = 0; i < n; i++) {
        getline(cin, inp);
        if (inp[0] >= '0' && inp[0] <= '9') {
            int nu = stoi(inp);
            if (nu / 13 > 0) cout << D2[nu / 13];
            if (nu / 13 > 0 && nu % 13 > 0) cout << " ";
            if (nu % 13 > 0 || nu == 0) cout << D1[nu % 13];
        } else {
            int t1 = 0, t2 = 0;
            string s1 = inp.substr(0, 3), s2;
            if (inp.size() > 4) s2 = inp.substr(4, 3);
            for (int j = 0; j <= 12; j++) {
                if (s1 == D1[j] || s2 == D1[j]) t1 = j;
                if (s1 == D2[j]) t2 = j;
            }
            cout << t2 * 13 + t1;
        }
        cout << "\n";
    }
}

