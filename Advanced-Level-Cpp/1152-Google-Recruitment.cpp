#include <iostream>
using namespace std;
bool is_prime(int x) {
    if (x <= 1) return false;
    for (int i = 2; i * i <= x; i++) {
        if (x % i == 0) return false;
    }
    return true;
}
int main() {
    int l, k;
    string s;
    cin >> l >> k >> s;
    for (int i = 0; i + k <= s.size(); i++) {
        string ts = s.substr(i, k);
        int a = stoi(ts);
        if (is_prime(a)) {
            cout << ts << "\n";
            return 0;
        }
    }
    cout << "404\n";
    return 0;
}

