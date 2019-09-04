#include <iostream>
#include <vector>
#include <string>
using namespace std;
long N, B;
vector<long> num;
string output = "Yes";
int main()
{
    cin >> N >> B;
    while (N != 0) {
        num.push_back(N % B);
        N /= B;
    }
    for (int i = 0; i < num.size() / 2; i++) {
        if (num[i] != num[num.size()-i-1]) {
            output = "No";
            break;
        }
    }
    cout << output << endl;
    for (int i = num.size() - 1; i >= 0; i--) {
        if (i != num.size() - 1) {
            cout << " ";
        }
        cout << num[i];
    }
    cout << endl;
    return 0;
}
