#include <algorithm>
#include <iostream>
#include <vector>
#include <map>
using namespace std;
bool is_prime(int x) {
    if (x <= 1) return false;
    for (int i = 2; i * i <= x; i++) {
        if (x % i == 0) return false;
    }
    return true;
}
int main() {
    int n, k, id;
    cin >> n;
    vector<bool> checked(n, false);
    map<int, int> pemap;
    for (int i = 0; i < n; i++) {
        cin >> id;
        pemap[id] = i;
    }
    cin >> k;
    for (int i = 0; i < k; i++) {
        int id;
        cin >> id;
        printf("%04d: ", id);
        if (pemap.find(id) == pemap.end()) {
            printf("Are you kidding?\n");
        } else {
            int idx = pemap[id];
            if (checked[idx]) {
                printf("Checked\n");
            } else {
                if (idx == 0) { printf("Mystery Award\n"); }
                else if (is_prime(idx + 1)) { printf("Minion\n"); }
                else { printf("Chocolate\n"); }
                checked[idx] = true;
            }
        }
    }
    return 0;
}

