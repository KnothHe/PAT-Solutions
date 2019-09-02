#include <iostream>
using namespace std;
int main() {
    int sum = 0;
    const string E[] = {"zero", "one", "two", "three", "four", "five", "six",
        "seven", "eight", "nine"};
    string n;
    cin >> n;
    for (char c : n) { sum += c - '0'; }
    string rs = to_string(sum);
    cout << E[rs[0] - '0'];
    for (int i = 1; i < rs.size(); i++) {
        cout << " " << E[rs[i] - '0'];
    }
    return 0;
}

