#include <iostream>
#include <vector>
#include <string>
using namespace std;
inline int charToInt(char c) {
    return c - '0';
}
inline char intToChar(int n) {
    return n + '0';
}
string doubleNumber(string input) {
    string res;
    int carry = 0;
    for (int i = input.size() - 1; i >= 0; i--) {
        int n = charToInt(input[i]) * 2 + carry;
        res = intToChar(n % 10) + res;
        carry = n / 10;
    }
    if (carry != 0) {
        res = intToChar(carry) + res;
    }
    return res;
}
void countChars(string num, vector<int>& cnt) {
    for (const auto &c : num) {
        cnt[charToInt(c)]++;
    }
}
int main() {
    string old_num, new_num;
    vector<int> old_cnt(10, 0), new_cnt(10, 0);
    cin >> old_num;
    new_num = doubleNumber(old_num);
    countChars(old_num, old_cnt);
    countChars(new_num, new_cnt);
    string output = "Yes";
    for (int i = 0; i < 10; i++) {
        if (old_cnt[i] != new_cnt[i]) {
            output = "No";
            break;
        }
    }
    cout << output << endl;
    for (const auto &c : new_num) {
        cout << c;
    }
    cout << endl;
}
