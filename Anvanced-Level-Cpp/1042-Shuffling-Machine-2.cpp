/*
 * Reference:
 *  https://www.liuchuo.net/archives/2019
 */
#include <iostream>
#include <vector>
#include <string>
using namespace std;
int main() {
    const int N = 55;
    vector<int> start(N), end(N), next(N);
    int k;
    cin >> k;
    for (int i = 1; i < N; i++) {
        cin >> next[i];
        start[i] = i;
    }
    for (int i = 0; i < k; i++) {
        for (int j = 1; j < N; j++) {
            end[next[j]] = start[j];
        }
        start = end;
    }
    string chs = "SHCDJ";
    for (int i = 1; i < N; i++) {
        end[i]--;
        if (i != 1) cout << " ";
        cout << chs[end[i]/13] << end[i]%13 + 1;
    }
    return 0;
}
