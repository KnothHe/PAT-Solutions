#include <iostream>
using namespace std;
using ll = long long;
struct Rat {
    ll num, den;
};
ll gcd(ll a, ll b) {
    if (b) while ((a %= b) && (b %= a)) {  }
    return a + b;
}
void rat_simp(Rat &r) {
    if (r.den == 0 || r.num == 0) return;
    ll g = gcd(r.num, r.den);
    r.num /= g;
    r.den /= g;
    if (r.den < 0) { r.num = -r.num; r.den = -r.den; }
}
string rat_str(Rat &r) {
    string rs;
    if (r.den == 0) { return "Inf"; }
    if (r.num == 0) { return "0"; }
    ll int_part = abs(r.num) / r.den;
    ll num_part = abs(r.num) % r.den;
    if (int_part != 0) rs.append(to_string(int_part));
    if (int_part != 0 && num_part != 0) rs.append(" ");
    if (num_part != 0) rs.append(to_string(num_part) +  "/" + to_string(r.den));
    if (r.num < 0) rs.insert(0, "(-").append(")");
    return rs;
}
void rat_cal_and_print(Rat r1, Rat r2, char op) {
    Rat rs;
    switch (op) {
        case '+' :
            rs.num = r1.num * r2.den + r2.num * r1.den;
            rs.den = r1.den * r2.den;
            break;
        case '-' :
            rs.num = r1.num * r2.den - r2.num * r1.den;
            rs.den = r1.den * r2.den;
            break;
        case '*' :
            rs.num = r1.num * r2.num;
            rs.den = r1.den * r2.den;
            break;
        case '/' :
            if (r2.num == 0) rs.den = 0;
            else {
                rs.num = r1.num * r2.den;
                rs.den = r1.den * r2.num;
            }
            break;
    }
    rat_simp(rs);
    cout << rat_str(r1) << " " << op << " " << rat_str(r2)
        << " = " << rat_str(rs) << "\n";
}
int main() {
    Rat r1, r2;
    scanf("%lld/%lld %lld/%lld", &r1.num, &r1.den, &r2.num, &r2.den);
    rat_simp(r1);
    rat_simp(r2);
    rat_cal_and_print(r1, r2, '+');
    rat_cal_and_print(r1, r2, '-');
    rat_cal_and_print(r1, r2, '*');
    rat_cal_and_print(r1, r2, '/');
    return 0;
}

