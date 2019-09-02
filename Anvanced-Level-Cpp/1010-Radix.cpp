#include <algorithm>
#include <iostream>
using namespace std;
long long convert(string n, int r) {
    long long rs = 0;
    for (char ch : n) {
        int c = isdigit(ch) ? ch - '0' : ch - 'a' + 10;
        rs = rs * r + c;
    }
    return rs;
}
long long findRadix(string n, long long num) {
    char it = *max_element(n.begin(), n.end());
    long long low = (isdigit(it) ? it - '0' : it - 'a' + 10) + 1;
    long long high = max(num, low);
    while (low <= high) {
        long long mid = (low + high) / 2;
        long long t = convert(n, mid);
        if (t == num) { return mid; }
        else if (t < 0 || t > num) high = mid - 1;
        else low = mid + 1;
    }
    return -1;
}
int main() {
    string n1, n2;
    int tag, radix;
    cin >> n1 >> n2 >> tag >> radix;
    if (tag == 2) { swap(n1, n2); }
    int r = findRadix(n2, convert(n1, radix));
    if (r == -1) { cout << "Impossible"; }
    else { cout << r; }
    return 0;
}

