#include <iostream>
#include <vector>
using namespace std;
const int inf = 99999999;
int main() {
    int n, m, src, dst, tcur;
    cin >> n >> m;
    vector<vector<int>> tis(n, vector<int>(n, inf));
    vector<vector<int>> les(n, vector<int>(n, inf));
    for (int i = 0; i < m; i++) {
        int v1, v2, ow, len, t;
        scanf("%d %d %d %d %d", &v1, &v2, &ow, &len, &t);
        tis[v1][v2] = t;
        les[v1][v2] = len;
        if (ow == 0) {
            tis[v2][v1] = t;
            les[v2][v1] = len;
        }
    }
    scanf("%d %d", &src, &dst);
    vector<int> distpre(n), timepre(n), distpath, timepath;
    vector<bool> mark(n, false);
    vector<int> dista(n, inf), timea(n, inf), timesum(n, inf), nodesum(n, inf);
    dista[src] = 0;
    for (int i = 0; i < n; i++) {
        int cur = -1, min_val = inf;
        for (int j = 0; j < n; j++) {
            if (!mark[j] && dista[j] < min_val) {
                min_val = dista[j];
                cur = j;
            }
        }
        if (cur == -1) break;
        mark[cur] = true;
        for (int j = 0; j < n; j++) {
            if (!mark[j] && les[cur][j] != inf) {
                if (dista[cur] + les[cur][j] < dista[j]) {
                    dista[j] = dista[cur] + les[cur][j];
                    distpre[j] = cur;
                    timesum[j] = timesum[cur] + tis[cur][j];
                } else if (dista[cur] + les[cur][j] == dista[j]
                        && timesum[cur] + tis[cur][j] < timesum[j]) {
                    distpre[j] = cur;
                    timesum[j] = timesum[cur] + tis[cur][j];
                }
            }
        }
    }
    tcur = dst;
    while (tcur != src) { distpath.push_back(tcur); tcur = distpre[tcur]; }
    distpath.push_back(src);
    fill(mark.begin(), mark.end(), false);
    timea[src] = 0;
    for (int i = 0; i < n; i++) {
        int cur = -1, min_val = inf;
        for (int j = 0; j < n; j++) {
            if (!mark[j] && timea[j] < min_val) {
                min_val = timea[j];
                cur = j;
            }
        }
        if (cur == -1) break;
        mark[cur] = true;
        for (int j = 0; j < n; j++) {
            if (!mark[j] && tis[cur][j] != inf) {
                if (timea[cur] + tis[cur][j] < timea[j]) {
                    timea[j] = timea[cur] + tis[cur][j];
                    timepre[j] = cur;
                    nodesum[j] = nodesum[cur] + 1;
                } else if (timea[cur] + tis[cur][j] == timea[j]
                        && nodesum[cur] + 1 < nodesum[j]) {
                    timepre[j] = cur;
                    nodesum[j] = nodesum[cur] + 1;
                }
            }
        }
    }
    tcur = dst;
    while (tcur != src) { timepath.push_back(tcur); tcur = timepre[tcur]; }
    timepath.push_back(src);
    printf("Distance = %d", dista[dst]); 
    if (distpath == timepath) {
        printf("; Time = %d: ", timea[dst]);
    } else {
        printf(": ");
        for (int i = distpath.size() - 1; i >= 0; i--) {
            printf("%d", distpath[i]);
            if (i != 0) printf(" -> ");
        }
        printf("\nTime = %d: ", timea[dst]);
    }
    for (int i = timepath.size() - 1; i >= 0; i--) {
        printf("%d", timepath[i]);
        if (i != 0) printf(" -> ");
    }
    return 0;
}
