#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
using namespace std;
struct Bill {
    string name;
    int age, worth;
};
int main() {
    int n, k;
    cin >> n >> k;
    vector<Bill> bills(n);
    for (int i = 0; i < n; i++) {
        cin >> bills[i].name >> bills[i].age >> bills[i].worth;
    }
    sort(bills.begin(), bills.end(), [](auto &lhs, auto &rhs) {
            return lhs.worth != rhs.worth ? lhs.worth > rhs.worth :
                (lhs.age != rhs.age ? lhs.age < rhs.age : lhs.name < rhs.name);
            });
    int q, age1, age2;
    for (int i = 1; i <= k; i++) {
        cout << "Case #" << i << ":" << endl;
        cin >> q >> age1 >> age2;
        int cnt = 0;
        for (auto &bill : bills) {
            if (cnt >= q) break;
            if (bill.age <= age2 && bill.age >= age1) {
                cout << bill.name << " " << bill.age << " " << bill.worth << endl;
                cnt++;
            }
        }
        if (cnt == 0) cout << "None" << endl;
    }
    return 0;
}
