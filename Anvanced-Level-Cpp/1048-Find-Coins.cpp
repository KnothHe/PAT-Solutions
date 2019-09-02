#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
int main() {
    int n, m;
    cin >> n >> m;
    vector<int> coins(n);
    for (int i = 0 ; i < n; i++) cin >> coins[i];
    sort(coins.begin(), coins.end());
    for (auto it = coins.begin(); it != coins.end(); it++) {
        auto pos = lower_bound(it+1, coins.end(), m-*it);
        if (pos != coins.end() && *pos + *it == m) {
            cout << *it << " " << *pos << endl;
            return 0;
        }
    }
    cout << "No Solution" << endl;
    return 0;
}
