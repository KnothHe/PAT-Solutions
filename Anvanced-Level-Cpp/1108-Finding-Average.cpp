#include <iostream>
#include <vector>
using namespace std;
bool is_legal(string s) {
    bool has_point = false;
    int beg = 0, pcnt = 0;
    if (s[0] == '-' || s[0] == '+') beg = 1;
    for (int i = beg; i < s.size(); i++) {
        if (has_point) { pcnt++; }
        if (!isdigit(s[i])) {
            if (s[i] == '.') {
                has_point = true;
            } else {
                return false;
            }
        }
    }
    if (pcnt > 2) return false;
    double num = stod(s);
    if (num > 1000 || num < -1000) return false;
    return true;
}
int main() {
    int n, cnt;
    cin >> n;
    double sum;
    string a;
    for (int i = 0; i < n; i++) {
        cin >> a;
        if (is_legal(a)) {
            sum += stod(a);
            cnt++;
        } else {
            cout << "ERROR: " << a << " is not a legal number\n";
        }
    }
    if (cnt == 0) printf("The average of 0 numbers is Undefined\n");
    else if (cnt == 1) printf("The average of 1 number is %.2lf\n", sum);
    else printf("The average of %d numbers is %.2lf\n", cnt, sum / cnt);
}

