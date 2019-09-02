#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
struct Stu {
    string name, id;
    int grade;
};
int main() {
    int n, g1, g2;
    cin >> n;
    vector<Stu> stus(n);
    for (int i = 0; i < n; i++) {
        cin >> stus[i].name >> stus[i].id >> stus[i].grade;
    }
    cin >> g1 >> g2;
    stus.erase(remove_if(stus.begin(), stus.end(), [g1, g2](auto &ele) {
                return ele.grade < g1 || ele.grade > g2;
                }), stus.end());
    sort(stus.begin(), stus.end(), [](auto &lhs, auto &rhs) {
            return lhs.grade > rhs.grade;
            });
    if (stus.empty()) { cout << "NONE\n";  }
    for (auto stu : stus) { cout << stu.name << " " << stu.id << "\n"; }
    return 0;
}

