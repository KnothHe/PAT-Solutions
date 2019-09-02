#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
int main() {
    int c, p;
    cin >> c;
    vector<int> cs(c);
    for (int i = 0; i < c; i++) {
        cin >> cs[i];
    }
    cin >> p;
    vector<int> ps(p);
    for (int i = 0; i < p; i++) {
        cin >> ps[i];
    }
    sort(cs.begin(), cs.end());
    sort(ps.begin(), ps.end());
    int get = 0;
    for (int i = 0; i < cs.size() && i < ps.size() && cs[i] < 0 && ps[i] < 0; i++) {
        get += cs[i] * ps[i];
    }
    for (int i = cs.size()-1, j = ps.size()-1; cs[i] > 0 && ps[j] > 0 && i >= 0 && j >= 0;
            i--, j--) {
        get += cs[i] * ps[j];
    }
    cout << get;
    return 0;
}
