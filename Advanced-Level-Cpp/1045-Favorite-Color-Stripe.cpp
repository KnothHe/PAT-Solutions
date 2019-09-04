/*
 * Reference:
 *  https://www.liuchuo.net/archives/2283
 *
 * For each color that appears in the favorite color, a order is given according
 * to the order in which they appear.
 * for example:
 *
 *  2 3 1 5 6
 *  | | | | |
 *  v v v v v
 *  0 1 2 3 4
 *
 * then this question just become longest not falling subsequence.
 *
 * for each color i that appears in final sequence, for all color j 
 * appear in this sequence before it, if order[j] less than or equals
 * to order[j], then dp[i] = max(dp[i], dp[j] + 1)
 *
 */
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
int main() {
    int n, m, l, color;
    cin >> n >> m;
    vector<int> order(n + 1, -1);
    for (int i = 0; i < m; i++) {
        cin >> color;
        order[color] = i;
    }
    cin >> l;
    vector<int> seq;
    for (int i = 0; i < l; i++) {
        cin >> color;
        if (order[color] != -1) seq.push_back(order[color]);
    }
    vector<int> dp(seq.size(), 1);
    for (int i = 0; i < seq.size(); i++) {
        for (int j = 0; j < i; j++) {
            if (seq[j] <= seq[i]) 
                dp[i] = max(dp[i], dp[j] + 1);
        }
    }
    cout << *max_element(dp.begin(), dp.end());
    return 0;
}
