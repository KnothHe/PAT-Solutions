#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;
int main() {
    int n, k;
    cin >> n >> k;
    string stud;
    map<string, vector<int>> studs;
    for (int i = 0; i < k; i++) {
        int c, m;
        cin >>  c >> m;
        for (int j = 0; j < m; j++) {
            cin >> stud;
            studs[stud].push_back(c);
        }
    }
    for (auto &p : studs) {
        auto &v = p.second;
        sort(v.begin(), v.end());
    }
    for (int i = 0; i < n; i++) {
        cin >> stud;
        cout << stud;
        cout << " " << studs[stud].size();
        for (auto n : studs[stud]) {
            cout << " " << n;
        }
        cout << endl;
    }
    return 0;
}
