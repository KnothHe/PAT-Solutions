#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
int main() {
    vector<string> sis;
    vector<string> sos;
    vector<string> ids;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        string id, in, out;
        cin >> id >> in >> out;
        ids.push_back(id);
        sis.push_back(in);
        sos.push_back(out);
    }
    cout << ids[distance(sis.begin(), min_element(sis.begin(), sis.end()))] << " "
        << ids[distance(sos.begin(), max_element(sos.begin(), sos.end()))] << "\n";
    return 0;
}
