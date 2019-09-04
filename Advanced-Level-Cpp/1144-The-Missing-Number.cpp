#include <iostream>
#include <set>
using namespace std;
int main() {
    int n, t;
    cin >> n;
    set<int> ns;
    for (int i = 0; i < n; i++) {
        cin >> t;
        ns.insert(t);
    }
    int rs = 1;
    while (ns.find(rs) != ns.end()) { rs++; }
    cout << rs << "\n";
    return 0;
}

