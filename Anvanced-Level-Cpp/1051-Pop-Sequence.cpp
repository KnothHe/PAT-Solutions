/*
 * Simulation
 *
 * see process comment part
 *
 * for example:
 *  5 6 4 3 7 2 1
 *
 *  1. push 1 2 3 4 5 to stack: 1 2 3 4 5, pop last element 5, -> 1 2 3 4
 *  2. push 6         to stack: 1 2 3 4 6, pop last element 6, -> 1 2 3 6
 *  3. push           to stack: 1 2 3 4,   pop last element 4, -> 1 2 3
 *  4. push           to stack: 1 2 3,     pop last element 3, -> 1 2
 *  5. push 7         to stack: 1 2 7,     pop last element 7, -> 1 2
 *  6. push           to stack: 1 2,       pop last element 2, -> 1
 *  7. push           to stack: 1,         pop last element 1, ->
 *
 */
#include <iostream>
#include <vector>
#include <stack>
using namespace std;
int main() {
    int n, m, k;
    cin >> m >> n >> k;
    vector<int> seq(n);
    int cur_num;
    for (int i = 0; i < k; i++) {
        // read
        for (int j = 0; j < n; j++) cin >> seq[j];
        // process begin
        int num = 1;
        stack<int> st;
        for (int j = 0; j < n; j++) {
            if (st.empty() || st.top() != seq[j]) {
                while (num <= seq[j]) {
                    st.push(num);
                    num++;
                }
            }
            if (st.top() != seq[j] || st.size() > m) break;
            else st.pop();
        }
        // process end
        // result
        if (st.empty()) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    return 0;
}
