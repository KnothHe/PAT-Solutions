/*
 * use sum to record sum of numbers between l and r;
 * l and r both less than n.
 * If sum < m, then increase r, and sum will increase.
 * If sum > m, then increase l, and sum will decrease.
 * If sum == m, then push l and r to ans vector, and increase r.
 */
#include <iostream>
#include <vector>
using namespace std;
int main() {
    int n, m;
    cin >> n >> m;
    vector<int> chains(n);
    vector<vector<int>> ans;
    for (int i = 0; i < n; i++) {
        cin >> chains[i];
    }
    int l = 0, r = 0, sum = chains[0], min_sum = 1 << 30;
    while (r < n) {
        if (sum == m) {
            ans.push_back({l + 1, r + 1});
            r++;
            sum += chains[r];
        } else if (sum < m) {
            r++;
            sum += chains[r];
        } else if (sum > m) {
            if (sum < min_sum) min_sum = sum;
            sum -= chains[l];
            l++;
        }
    }
    if (ans.size() == 0) {
        int l = 0, r = 0; sum = chains[0];
        while (r < n) {
            if (sum == min_sum) {
                ans.push_back({l + 1, r + 1});
                r++;
                sum += chains[r];
            } else if (sum < m) {
                r++;
                sum += chains[r];
            } else {
                sum -= chains[l];
                l++;
            }
        }
    }
    for (auto &vec : ans) {
        cout << vec[0] << "-" << vec[1] << endl;
    }
    return 0;
}
