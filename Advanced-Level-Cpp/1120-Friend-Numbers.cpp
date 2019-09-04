#include <iostream>
#include <set>
using namespace std;
int get_num(int x) {
    int rs = 0;
    while (x != 0) {
        rs += x % 10;
        x /= 10;
    }
    return rs;
}
int main() {
    int n, t;
    cin >> n;
    set<int> rs;
    for (int i = 0; i < n; i++) {
        cin >> t;
        rs.insert(get_num(t));
    }
    cout << rs.size() << "\n";
    for (auto it = rs.begin(); it != rs.end(); it++) {
        if (it != rs.begin()) cout << " ";
        cout << (*it);
    }
    return 0;
}

