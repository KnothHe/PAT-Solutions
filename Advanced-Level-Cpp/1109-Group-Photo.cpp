#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
struct Peop {
    string name;
    int heig;
};
int main() {
    int n, k;
    cin >> n >> k;
    vector<Peop> ps(n);
    for (int i = 0; i < n; i++) {
        cin >> ps[i].name >> ps[i].heig;
    }
    sort(ps.begin(), ps.end(), [](auto &lhs, auto &rhs) {
            return lhs.heig != rhs.heig ? lhs.heig > rhs.heig :
                lhs.name < rhs.name;
            });
    for (int row = k, pt = 0; row > 0; row--) {
        int size = n / k;
        if (row == k) size = n - n / k * (k - 1);
        vector<string> ts(size);
        ts[size / 2] = ps[pt].name;
        int left = size / 2 - 1, right = size / 2 + 1;
        for (int i = pt + 1; i < pt + size; i += 2) {
            ts[left--] = ps[i].name;
        }
        for (int i = pt + 2; i < pt + size; i += 2) {
            ts[right++] = ps[i].name;
        }
        cout << ts[0];
        for (int i = 1; i < size; i++) {
            cout << " " << ts[i];
        }
        cout << "\n";
        pt += size;
    }
    return 0;
}

