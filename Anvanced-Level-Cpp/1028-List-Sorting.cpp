#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
struct Record {
    string id, name;
    int score;
} record;
int main() {
    int N, C;
    cin >> N >> C;
    vector<Record> records(N);
    for (int i = 0; i < N; i++) {
        cin >> record.id >> record.name >> record.score;
        records[i] = record;
    }
    sort(records.begin(), records.end(), [C](auto &lhs, auto &rhs) {
            switch (C) {
                case 2 : return lhs.name != rhs.name ? lhs.name <= rhs.name :
                    lhs.id < rhs.id;
                case 3 : return lhs.score != rhs.score ? lhs.score <= rhs.score :
                    lhs.id < rhs.id;
                default : return lhs.id < rhs.id;
            }});
    for (auto &r : records) {
        cout << r.id << " " << r.name << " " << r.score << endl;
    }
    return 0;
}

