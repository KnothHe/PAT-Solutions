#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
struct Student {
    string name, id;
    int grade;
} stud;
vector<Student> boys;
vector<Student> girls;
int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        string gender;
        cin >> stud.name >> gender >> stud.id >> stud.grade;
        if (gender == "M") boys.push_back(stud);
        else girls.push_back(stud);
    }
    auto cmp = [](auto &lhs, auto &rhs) {
        return lhs.grade < rhs.grade;
    };
    auto g = max_element(girls.begin(), girls.end(), cmp);
    auto b = min_element(boys.begin(), boys.end(), cmp);
    if (g == girls.end()) cout << "Absent" << endl;
    else cout << g->name << " " << g->id << endl;
    if (b == boys.end()) cout << "Absent" << endl;
    else cout << b->name << " " << b->id << endl;
    if (g == girls.end() || b == boys.end()) cout << "NA" << endl;
    else cout << abs(b->grade - g->grade) << endl;
    return 0;
}
