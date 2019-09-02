#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main() {
    int m, n, s;
    cin >> m >> n >> s;
    vector<string> ss(m), rs;
    for (int i = 0; i < m; i++) {
        cin >> ss[i];
    }
    if (m < s) { cout << "Keep going...\n"; }
    else {
        for (int i = s-1; i < m; ) {
            if (find(rs.begin(), rs.end(), ss[i]) == rs.end()) {
                rs.push_back(ss[i]);
                i += n;
            } else { i++; }
        }
    }
    for (int i = 0; i < rs.size(); i++) {
        cout << rs[i] << "\n";
    }
    return 0;
}

