/*
 * Reference:
 *  https://www.liuchuo.net/archives/2461
 */
#include <algorithm>
#include <vector>
#include <cstdio>
using namespace std;
const int INF = 1 << 30;
struct Station {
    double price, dis;
};
int main() {
    int cmax, d, davg, n;
    scanf("%d %d %d %d", &cmax, &d, &davg, &n);
    vector<Station> stats(n + 1);
    stats[0] = {0, static_cast<double>(d)};
    for (int i = 1; i <= n; i++) {
        scanf("%lf %lf", &stats[i].price, &stats[i].dis);
    }
    sort(stats.begin(), stats.end(), [](auto &lhs, auto &rhs){
                return lhs.dis < rhs.dis;
            });
    double now_price(0.0), now_dis(0.0), total_price(0.0), max_dis(0.0), left_dis(0.0);
    if (stats[0].dis != 0) {
        printf("The maximum travel distance = 0.00");
        return 0;
    } else {
        now_price = stats[0].price;
    }
    while (now_dis < d) {
        max_dis = now_dis + cmax * davg;
        double min_price = INF, min_price_dis = 0.0;
        bool flag = true;
        for (int i = 1; i <= n && stats[i].dis <= max_dis; i++) {
            if (stats[i].dis <= now_dis) continue;
            if (stats[i].price < now_price) {
                total_price += now_price * (stats[i].dis - now_dis - left_dis) / davg;
                left_dis = 0.0;
                now_price = stats[i].price;
                now_dis = stats[i].dis;
                flag = false;
                break;
            }
            if (stats[i].price < min_price) {
                min_price = stats[i].price;
                min_price_dis = stats[i].dis;
            }
        }
        if (flag && min_price != INF) {
            total_price += now_price * (cmax - left_dis / davg);
            left_dis = now_dis + cmax * davg - min_price_dis;
            now_price = min_price;
            now_dis = min_price_dis;
        }
        if (flag && min_price == INF) {
            printf("The maximum travel distance = %.2lf", now_dis + cmax * davg);
            return 0;
        }
    }
    printf("%.2f", total_price);
    return 0;
}
