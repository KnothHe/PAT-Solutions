#include <iostream>
#include <vector>
#include <string>
using namespace std;
int main() {
    int k;
    cin >> k;
    string inp;
    cin >> inp;
    vector<bool> stucked(256, true);
    for (int i = 0; i < inp.size();) {
        if (i+1 < inp.size() && inp[i] != inp[i+1]) { stucked[inp[i]] = false; i++; }
        else {
            int tcnt = 1;
            for (int j = i+1; j < i+k && j < inp.size() && inp[j] == inp[j-1]; j++) {
                tcnt++;
            }
            if (tcnt != k) { stucked[inp[i]] = false; }
            i += tcnt;
        }
    }
    string rs, ss;
    for (int i = 0; i < inp.size();) {
        rs.append(1, inp[i]);
        if (stucked[inp[i]]) { 
            if (ss.find(inp[i]) == string::npos) { ss.append(1, inp[i]); }
            i += k; 
        } else { i++; }
    }
    cout << ss << "\n" << rs << "\n";
    return 0;
}

