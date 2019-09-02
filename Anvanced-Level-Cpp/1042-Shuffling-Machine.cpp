/*
 * First, initialize a cards array,
 * then save the input to the shuffling array,
 * finally scramble the cards array k times according to the shuffling array;
 */
#include <iostream>
#include <vector>
#include <string>
using namespace std;
vector<string> cards(54), temp(54);
vector<int> shuffling(54);
string chs = "SHCD";
int k;
void init() {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 13; j++) {
            cards[i*13 + j] = chs[i] + to_string(j+1);
        }
    }
    cards[52] = "J1";
    cards[53] = "J2";
}
int main() {
    init();
    cin >> k;
    for (int i = 0; i < 54; i++) {
        cin >> shuffling[i];
        shuffling[i]--;
    }
    for (int i = 0; i < k; i++) {
        for (int j = 0; j < 54; j++) {
            temp[shuffling[j]] = cards[j];
        }
        cards = temp;
    }
    for (int i = 0; i < cards.size(); i++) {
        if (i != 0) cout << " ";
        cout << cards[i];
    }
    return 0;
}
