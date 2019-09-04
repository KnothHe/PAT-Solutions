/*
 * If it's error is time limit exceeded, try using scanf and printf for input and output.
 */
#include <algorithm>
#include <iostream>
#include <vector>
#include <cstdio>
using namespace std;
int main() {
    int n, k, c, t;
    cin >> n >> k;
    vector<string> names(n);
    vector<vector<int>> courses(k+1);
    for (int i = 0; i < n; i++) {
        cin >> names[i] >> c;
        for (int j = 0; j < c; j++) {
            cin >> t;
            courses[t].push_back(i);
        }
    }
    for (int i = 1; i < k+1; i++) {
        sort(courses[i].begin(), courses[i].end(), [&names](auto &lhs, auto &rhs){
                return names[lhs] < names[rhs];
                });
        printf("%d %zu\n", i, courses[i].size());
        for (const int &st : courses[i]) {
            printf("%s\n", names[st].c_str());
        }
    }
    return 0;
}
