#include <cstdio>
using namespace std;
int main() {
    long long a, b, c, d, e, f, g;
    scanf("%lld.%lld.%lld %lld.%lld.%lld", &a, &b, &c, &d, &e, &f);
    long long num = a * 29 * 17 + b * 29 + c + d * 29 * 17 + e * 29 + f;
    g = num / (29 * 17);
    num %= 29 * 17;
    printf("%lld.%lld.%lld\n", g, num / 29, num % 29);
    return 0;
}

