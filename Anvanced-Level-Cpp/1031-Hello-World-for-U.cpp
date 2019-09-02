#include <iostream>
#include <string>
using namespace std;
string u;
int main() {
    cin >> u;
    int N = u.size() + 2;
    int n1 = N / 3, n2 = N / 3 + N % 3;
    n1 = (N - n2 + 2) / 2;
    int li = 0, ri = u.size() - 1;
    while (li < ri && ri - li + 1 != n2) {
        cout << u[li] << string(n2 - 2, ' ') << u[ri] << '\n';
        li++; ri--;
    }
    cout << u.substr(li, ri - li + 1);
    return 0;
}

