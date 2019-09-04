/*
 * Calculate the number of occurrences of 1 per digit on the number.
 * Set current number to now, set the number of left hand of now to left,
 * set the number of right hand of now to right, set w to the weight of now.
 *
 * for example:
 *
 *   left
 *    |
 *   ---  right
 *   | |   |
 *   v v   v
 *   123 4 5
 *       ^
 *       |
 *      now
 *
 * left is 123, now is 4, right is 5, and w is 10
 *
 * for each now:
 *  0,      occurrences is  left      * w,
 *  1,      occurrences is  left      * w + right + q,
 *  others, occurrences is (left + 1) * w.
 *
 */
#include <iostream>
using namespace std;
int main() {
    long n, count = 0, w = 1;
    cin >> n;
    while (n / w != 0) {
        int left = n / (w * 10), now = (n % (w * 10)) / w, right = n % w;
        if (now == 0) count += left * w;
        else if (now == 1) count += left * w + right + 1;
        else count += (left + 1) * w;
        w *= 10;
    }
    cout << count << endl;
    return 0;
}
