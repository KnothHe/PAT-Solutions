#include <iostream>
using namespace std;
int main() {
    int cnt = 0, cur = 0, n, t;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> t;
        if (t > cur) {
            cnt += (t - cur) * 6;
        } else {
            cnt += (cur - t) * 4;
        }
        cnt += 5;
        cur = t;
    }
    cout << cnt << "\n";
    return 0;
}

