#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
struct Term {
    int exp;
    double coeff;
};
int main() {
    int n, exp;
    double coeff;
    vector<Term> a, b, rs;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> exp >> coeff;
        a.push_back({ exp, coeff });
    }
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> exp >> coeff;
        b.push_back({ exp, coeff });
    }
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());
    int i = 0, j = 0;
    while (i < a.size() || j < b.size()) {
        if (i >= a.size()) { rs.push_back(b[j]); j++; }
        else if (j >= b.size()) { rs.push_back(a[i]); i++; }
        else if (a[i].exp == b[j].exp) {
            double tcoeff = a[i].coeff + b[j].coeff;
            if (tcoeff != 0) { rs.push_back({ a[i].exp, tcoeff }); }
            i++; j++;
        } else {
            if (a[i].exp < b[j].exp) {
                rs.push_back(a[i]); i++;
            } else {
                rs.push_back(b[j]); j++;
            }
        }
    }
    printf("%zu", rs.size());
    for (i = rs.size() - 1; i >= 0; i--) {
        printf(" %d %.1lf", rs[i].exp, rs[i].coeff);
    }
    return 0;
}

