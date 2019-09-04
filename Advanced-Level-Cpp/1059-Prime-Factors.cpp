#include <iostream>
using namespace std;
int main() {
    long long num, nf = 0;
    cin >> num;
    cout << num << "=";
    if (num == 1) cout << 1;
    for (long long i = 2; i <= num; i++) {
        int cnt = 0;
        while (num % i == 0) {
            cnt++;
            num /= i;
        }
        if (cnt > 0) {
            if (nf != 0) cout << "*";
            cout << i;
            if (cnt > 1) cout << "^" << cnt;
            nf++;
        }
    }
    return 0;
}

