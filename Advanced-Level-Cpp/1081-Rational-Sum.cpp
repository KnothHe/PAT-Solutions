/*
 * The template code to cacluate gcd:
 * int a, int b:
 * if (b) while ((a %= b) && (b %= a)) ;
 * return a + b;
 */
#include <iostream>
#include <vector>
#include <numeric>
using namespace std;
using ll = long long;
struct Rat {
    ll num, den;
};
int gcd(int a, int b) {
    if (b) while ((a %= b) && (b %= a)) ;
    return a + b;
}
Rat rat_add(Rat a, Rat b) {
    ll num = a.num * b.den + b.num * a.den;
    ll den = a.den * b.den;
    ll g = gcd(num, den);
    return { num / g, den / g };
}
int main() {
    int n;
    ll a, b;
    scanf("%d", &n);
    Rat rs({ 0, 1 });
    for (int i = 0; i < n; i++) {
        scanf("%lld/%lld", &a, &b);
        rs = rat_add(rs, { a, b });
    }
    if (rs.num == 0) cout << "0\n";
    else {
        int int_part = rs.num / rs.den, num_part = rs.num % rs.den;
        if (int_part != 0) cout << int_part;
        if (int_part != 0 && num_part != 0) cout << " ";
        if (num_part != 0) cout << num_part << "/" << rs.den << "\n";
    }
    return 0;
}

