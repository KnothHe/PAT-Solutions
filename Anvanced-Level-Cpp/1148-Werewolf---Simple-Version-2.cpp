#include <iostream>
#include <vector>
using namespace std;
int main() {
    int n;
    cin >> n;
    vector<int> player(n + 1);
    for (int i = 1; i <= n; i++) { cin >> player[i]; }
    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            vector<int> role(n + 1, 1), lier;
            role[i] = role[j] = -1;
            for (int k = 1; k <= n; k++) {
                if (player[k] * role[abs(player[k])] < 0) lier.push_back(k);
            }
            if (lier.size() == 2 && role[lier[0]] + role[lier[1]] == 0) {
                cout << i << " " << j << "\n";
                return 0;
            }
        }
    }
    cout << "No Solution\n";
    return 0;
}

