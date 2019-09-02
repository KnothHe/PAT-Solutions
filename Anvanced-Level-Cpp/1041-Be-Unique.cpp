#include <iostream>
#include <vector>
using namespace std;
int main() {
    const int MAX_N = 10005;
    vector<int> nums(MAX_N, 0);
    int n;
    cin >> n;
    vector<int> ns;
    for (int i = 0; i < n; i++) {
        int t_n;
        cin >> t_n;
        nums[t_n] += 1;
        ns.push_back(t_n);
    }
    for (auto &num : ns) {
        if (nums[num] == 1) {
            cout << num;
            return 0;
        }
    }
    cout << "None";
    return 0;
}
