#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
const vector<string> NUM( { "ling", "yi", "er", "san", "si",
        "wu", "liu", "qi", "ba", "jiu" } );
const vector<string> P( { "", "Shi", "Bai", "Qian" } );
int main() {
    int n;
    cin >> n;
    bool is_neg = n < 0;
    n = abs(n);
    string n_str = to_string(n);
    reverse(n_str.begin(),n_str.end());
    string rs, ts;
    int p2 = (n / 10000) % (10000), p3 = n / (100000000);
    for (int i = 0; i < n_str.size(); i++) {
        ts.clear();
        if (n_str[i] != '0') {
            ts.append(NUM[n_str[i]-'0']); // number
            if (i % 4 > 0) ts.append(" ").append(P[i % 4]); // weight
        } else {
            if (!rs.empty() && rs.substr(0, 4) != "ling"
                    && rs.substr(0, 3) != "Wan") {
                ts.append("ling"); // add "ling" ?
            }
        }
        if (!ts.empty() && !rs.empty()) ts.append(" "); // add " " ?
        if (i == 4 || i == 8) {
            if (i == 4 && p2 > 0) { ts.append("Wan"); } // add "Wan" ?
            if (i == 8 && p3 > 0) { ts.append("Yi"); } // add "Yi" ?
            if (!ts.empty() && !rs.empty()) ts.append(" "); // add " "?
        }
        rs.insert(0, ts);
    }
    if (n == 0) cout << "ling\n"; // just 0
    else {
        if (is_neg) cout << "Fu ";
        cout << rs << "\n";
    }
    return 0;
}

