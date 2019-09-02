#include <algorithm>
#include <cstdio>
#include <vector>
using namespace std;
struct Mooncake {
    double num, pro, unit;
};
int main() {
    int n, d;
    scanf("%d %d", &n, &d);
    vector<Mooncake> mcs(n);
    for (int i = 0; i < n; i++) scanf("%lf", &mcs[i].num);
    for (int i = 0; i < n; i++) {
        scanf("%lf", &mcs[i].pro);
        mcs[i].unit = mcs[i].pro / mcs[i].num;
    }
    sort(mcs.begin(), mcs.end(), [](auto &lhs, auto &rhs) {
            return lhs.unit > rhs.unit; 
            });
    double pro = 0.0;
    for (int i = 0; i < mcs.size(); i++) {
        if (mcs[i].num <= d) { pro += mcs[i].pro; } 
        else {
            pro += mcs[i].unit * d;
            break;
        }
        d -= mcs[i].num;
    }
    printf("%.2lf", pro);
     return 0;
}

