#include <iostream>
#include <string>
using namespace std;
int main() {
    string str;
    getline(cin, str);
    int max_len = 1;
    for (int i = 1; i < str.size()-1; i++) {
        int l = i-1, r = i+1, len = 1;
        while (l >= 0 && r < str.size() && str[l] == str[r]) {
            len += 2;
            l--; r++;
        }
        max_len = max_len > len ? max_len : len;
        l = i, r = i+1, len = 0;
        while (l >= 0 && r < str.size() && str[l] == str[r]) {
            len += 2;
            l--; r++;
        }
        max_len = max_len > len ? max_len : len;
    }
    cout << max_len;
    return 0;
}
