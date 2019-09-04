/*
 * Reference:
 *  https://www.liuchuo.net/archives/2265
 *
 * Binary Indexed Tree
 *
 * Suppose there is an array A, A[i] is the number of times i appears in the stack st.
 *
 * Binary Indexed Tree Array c is an array can quickly get the sum of number less than
 * or equal to i.
 *
 * Generally, BIT array can efficiently update elements and calculate prefix sums in
 * a table of numbers. [from wikipedia]
 *
 * Since we can get less than or equal to the number of a number in the stack st, we
 * can use binary seach to find the median.
 *
 * Meanwhile, change the number of occurrences of a number is logarithmic time.
 *
 */
#include <iostream> 
#include <string>
#include <vector>
#include <stack>
using namespace std;
const int max_n = 100005;
vector<int> bit(max_n, 0);
stack<int> st;
inline int lowbit(int x) { return x & (-x); }
void edit(int x, int delta) {
    for (int i = x; i < max_n; i += lowbit(i)) { bit[i] += delta; }
}
int get_sum(int x) {
    int sum = 0;
    for (int i = x; i >= 1; i -= lowbit(i)) { sum += bit[i]; }
    return sum;
}
int peek_median() {
    int left = 1, right = max_n, mid, k = (st.size() + 1) / 2;
    while (left < right) {
        mid = (left + right) / 2;
        if (get_sum(mid) >= k) right = mid;
        else left = mid + 1;
    }
    return left;
}
int main() {
    int n, t;
    cin >> n;
    string op;
    for (int i = 0; i < n; i++) {
        cin >> op;
        switch (op[1]) {
            case 'u' :
                cin >> t;
                st.push(t);
                edit(t, 1);
                break;
            case 'o' :
                if (st.empty()) cout << "Invalid\n";
                else {
                    edit(st.top(), -1);
                    cout << st.top() << "\n";
                    st.pop();
                }
                break;
            default :
                if (st.empty()) cout << "Invalid\n";
                else {
                    cout << peek_median() << "\n";
                }
        }
    }
    return 0;
}

