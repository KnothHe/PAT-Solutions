#include <iostream>
#include <string>
using namespace std;
int main() {
    int n, r;
    cin >> n;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        int a = stoi(s.substr(0, s.size() / 2));
        int b = stoi(s.substr(s.size() / 2));
        int r = stoi(s);
        if (a * b != 0 && r % (a * b) == 0) {
            cout << "Yes\n";
        } else { cout << "No\n"; }
    }
    return 0;
}

