/*
 * Reference:
 *  https://www.liuchuo.net/archives/2021
 * 
 * dist[i] is distance between 1 and i+1, 
 * the last value of dist array is sum of distance.
 * so minimum distance between d1 and d2 (assuming d2 greater than or equals to d1)
 * is minimum distance between dist[d2-1] - dist[d1-1] 
 * and dist.back() - dist[d2-1] + dist[d1-1]
 *
 */
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
int main() {
    int n, m, d1, d2;
    cin >> n;
    vector<int> dist(n+1, 0);
    for (int i = 1; i <= n; i++) {
        cin >> dist[i];
        dist[i] += dist[i-1];
    }
    cin >> m;
    for (int i = 0; i < m; i++) {
        cin >> d1 >> d2;
        if (d1 > d2) swap(d1, d2);
        cout << min(dist[d2-1] - dist[d1-1],
                dist.back() - dist[d2-1] + dist[d1-1]) << endl;
    }
    return 0;
}
