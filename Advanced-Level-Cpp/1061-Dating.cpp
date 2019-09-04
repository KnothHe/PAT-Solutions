#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <cctype>
using namespace std;
vector<string> day({ "MON", "TUE", "WED", "THU", "FRI", "SAT", "SUN" });
int main() {
    string s1, s2, s3, s4;
    cin >> s1 >> s2 >> s3 >> s4;
    int len1 = min(s1.size(), s2.size());
    int len2 = min(s3.size(), s4.size());
    int flag = 0;
    string rs;
    for (int i = 0; i < len1; i++) {
        if (s1[i] == s2[i]) {
            char ch = s1[i];
            if (flag == 0 && ch >= 'A' && ch <= 'G') {
                rs.append(day[ch - 'A']).append(" ");
                flag++;
            } else if (flag == 1 && (isdigit(ch) || (ch >= 'A' && ch <= 'N'))){
                if (isdigit(ch)) { rs.append("0").append(1, ch); }
                else { rs.append(to_string(ch - 'A' + 10)); }
                rs.append(":");
                break;
            }
        }
    }
    for (int i = 0; i < len2; i++) {
        if (s3[i] == s4[i] && isalpha(s3[i])) {
            if (i <= 9) rs.append("0");
            rs.append(to_string(i));
        }
    }
    cout << rs << endl;
    return 0;
}

