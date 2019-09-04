#include <algorithm>
#include <iostream>
#include <map>
using namespace std;
int main() {
    int n, m, color;
    cin >> m >> n;
    map<int, int> colors;
    int half = n * m / 2;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> color;
            colors[color]++;
            if (colors[color] > half) {
                cout << color << endl;
                return 0;
            }
        }
    }
    return 0;
}
