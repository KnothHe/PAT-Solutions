/*
 * Reference:
 *  https://www.xzy1996.com/post/a7b8cdfd.html
 *
 *  Just travel and add some limit.
 *  1. sort this array
 *  2. if tsum + coins[cur] > m, stop this travel.
 *  3. sum is the sum of all coins, if sum is less than m, then we don't need to travel.
 *
 * Dp(0-1 bag) is better solution.
 *
 */
#include <algorithm>
#include <vector>
#include <cstdio>
using namespace std;
int n, m, sum = 0;
vector<int> coins;
vector<int> rs;
void travel(int cur, int tsum) {
    if (cur == n) return;
    if (tsum + coins[cur] == m) {
        rs.push_back(coins[cur]);
        printf("%d", rs[0]);
        for (int i = 1; i < rs.size(); i++) { printf(" %d", rs[i]); }
        exit(0);
    }
    // select this coin
    rs.push_back(coins[cur]);
    travel(cur + 1, tsum + coins[cur]);
    rs.pop_back();
    // not select 
    if (tsum + coins[cur] < m) travel(cur + 1, tsum);
}
int main() {
    scanf("%d %d", &n, &m);
    coins.resize(n);
    for (int i = 0; i < n; i++){
        scanf("%d", &coins[i]);
        sum += coins[i];
    }
    if (sum >= m) {
        sort(coins.begin(), coins.end());
        travel(0, 0);
    }
    printf("No Solution");
    return 0;
}

