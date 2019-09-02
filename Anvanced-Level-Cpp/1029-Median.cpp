/*
 * Reference:
 *  https://www.liuchuo.net/archives/2248
 */
#include <cstdio>
using namespace std;
const int MAX_N = 200005;
int k[MAX_N];
int main() {
    int n, m, t, cnt = 0;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &k[i]);
    }
    k[n + 1] = 0x7fffffff;
    scanf("%d", &m);
    int mid_pos = (n + m + 1) / 2, i = 1;
    for (int j = 0; j < m; j++) {
        scanf("%d", &t);
        while (k[i] < t) {
            cnt++;
            if (cnt == mid_pos) printf("%d", k[i]);
            i++;
        }
        cnt++;
        if (cnt == mid_pos) printf("%d", t);
    }
    while (i <= n) {
        cnt++;
        if (cnt == mid_pos) printf("%d", k[i]);
        i++;
    }
    return 0;
}

