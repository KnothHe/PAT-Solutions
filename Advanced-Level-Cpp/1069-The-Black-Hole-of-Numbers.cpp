#include <algorithm>
#include <cstdio>
#include <string>
using namespace std;
int main() {
    int n;
    scanf("%d", &n);
    do {
        int n1, n2;
        char tstr[10];
        sprintf(tstr, "%04d", n);
        string tn(tstr);
        sort(tn.begin(), tn.end(), greater_equal<char>());
        n1 = stoi(tn);
        sort(tn.begin(), tn.end(), less_equal<char>());
        n2 = stoi(tn);
        n = n1 - n2;
        printf("%04d - %04d = %04d\n", n1, n2, n);
    } while (n != 6174 && n != 0);
    return 0;
}

