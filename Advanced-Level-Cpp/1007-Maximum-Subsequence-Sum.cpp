#include <iostream>
#include <vector>
using namespace std;
int main() {
    int n;
    cin >> n;
    vector<int> ns(n);
    for (int i = 0; i < n; i++) { cin >> ns[i]; }
    int max_sum = -1, max_first = 0, max_last = 0, sum = -1, first;
    for (int i = 0; i < n; i++) {
        if (sum >= 0) {
            sum += ns[i];
        } else {
            sum = ns[i];
            first = ns[i];
        }
        if (sum > max_sum) {
            max_sum = sum;
            max_first = first;
            max_last = ns[i];
        }
    }
    if (max_sum < 0) { max_sum = 0; max_first = ns.front(); max_last = ns.back(); }
    cout << max_sum << " " << max_first << " " << max_last << "\n";
    return 0;
}

