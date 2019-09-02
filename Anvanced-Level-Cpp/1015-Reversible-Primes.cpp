#include <iostream>
using namespace std;
bool is_prime(int n)
{
    if (n <= 1) return false;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}
int reverse_number(int N, int D)
{
    int reversed = 0;
    while (N > 0) {
        reversed = reversed * D + N % D;
        N /= D;
    }
    return reversed;
}
int main()
{
    int N, D;
    while ((cin >> N) && N >= 0) {
        cin >> D;
        if (is_prime(N) && is_prime(reverse_number(N, D))) {
            cout << "Yes";
        } else {
            cout << "No";
        }
        cout << "\n";
    }
    return 0;
}
