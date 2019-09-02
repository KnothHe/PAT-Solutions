#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;
int main() {
    char R[] = {'W', 'T', 'L'};
    double rs = 1.0;
    vector<double> ns(3);
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) { cin >> ns[j]; }
        int max_idx = distance(ns.begin(), max_element(ns.begin(), ns.end()));
        printf("%c ", R[max_idx]);
        rs *= ns[max_idx];
    }
    printf("%.2lf\n", (rs * 0.65 - 1) * 2);
    return 0;
}

