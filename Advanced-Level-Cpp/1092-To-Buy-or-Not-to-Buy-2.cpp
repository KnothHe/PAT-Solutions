#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main() {
    string o, e;
    vector<int> arr(256, 0);
    cin >> o >> e;
    for (char c : o) { arr[c]++; }
    for (char c : e) { arr[c]--; }
    int missing = 0;
    for (int ele : arr) { if (ele < 0) { missing += -ele; } }
    if (missing == 0) { cout << "Yes " << o.size() - e.size(); }
    else { cout << "No " << missing; }
    return 0;
}

