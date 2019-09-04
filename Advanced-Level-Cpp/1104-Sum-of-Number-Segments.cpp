#include <iostream>
#include <vector>
using namespace std;
vector<double> ns;
int main() {
    int n;
    cin >> n;
    ns.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> ns[i];
    }
    double rs = 0.0;
    for (int i = 0; i < n; i++) { 
        rs += ns[i] * (n - i) * (i + 1);
    }
    printf("%.2lf", rs);
    return 0;
}

