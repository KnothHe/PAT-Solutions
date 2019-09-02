/*
 * Reference:
 *  https://www.liuchuo.net/archives/2180
 */
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
struct Record {
    string user;
    int final_rank, local_rank, location_number, score;
};
int N, K;
vector<Record> fin;
bool cmp(Record &lhs, Record &rhs) {
    return lhs.score != rhs.score ? lhs.score > rhs.score :
        lhs.user < rhs.user;
}
int main() {
    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> K;
        vector<Record> loc(K);
        for (int j = 0; j < K; j++) {
            cin >> loc[j].user >> loc[j].score;
            loc[j].location_number = i;
        }
        sort(loc.begin(), loc.end(), cmp);
        loc[0].local_rank = 1;
        fin.push_back(loc[0]);
        for (int r = 1; r < loc.size(); r++) {
            loc[r].local_rank = (loc[r].score == loc[r - 1].score) ?
                loc[r - 1].local_rank : r + 1;
            fin.push_back(loc[r]);
        }
    }
    sort(fin.begin(), fin.end(), cmp);
    fin[0].final_rank = 1;
    for (int r = 1; r < fin.size(); r++) {
        fin[r].final_rank = (fin[r].score == fin[r - 1].score) ?
            fin[r - 1].final_rank : r + 1;
    }
    cout << fin.size() << '\n';
    for (const auto &r : fin) {
        cout << r.user << " " << r.final_rank << " " 
            << r.location_number << " " << r.local_rank << '\n';
    }
    return 0;
}
