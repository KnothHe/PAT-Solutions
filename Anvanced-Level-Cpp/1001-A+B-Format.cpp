#include <algorithm>
#include <iostream>
using namespace std;
int main() {
    int a, b;
    cin >> a >> b;
    int r = a + b;
    string s = to_string(r), rs;
    for (int i = s.size() - 1, cnt = 1; i >= 0; i--) {
        rs.append(1, s[i]);
        if (cnt != 0 && cnt % 3 == 0 && i - 1 >= 0 && isdigit(s[i-1])) {
            rs.append(1, ',');
        }
        cnt++;
    }
    reverse(rs.begin(), rs.end());
    cout << rs << "\n";
    return 0;
}

