#include <iostream>
using namespace std;
int main() {
    int n;
    string d;
    cin >> d >> n;
    for (int i = 1; i < n; i++) {
        int cnt = 1;
        char pre_char = d[0];
        string rs;
        for (int j = 1; j < d.size(); j++) {
            if (d[j] == d[j-1]) { cnt++; }
            else {
                rs.append(1, pre_char).append(to_string(cnt));
                cnt = 1;
                pre_char = d[j];
            }
        }
        rs.append(1, pre_char).append(to_string(cnt));
        d = rs;
    }
    cout << d << "\n";
    return 0;
}

