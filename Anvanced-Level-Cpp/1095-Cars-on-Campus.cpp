/*
 * 1. Convert time to second-based.
 * 2. First sort is sorted by small id and time.
 * 3. After first sort, only paired records will be copy to another array prcs.
 *  In this process, record the maxiumu time of stay.
 * 4. Second sort is sorted by small time.
 * 5. Use lastidx to record last break index as next loop start index.
 *  We can reuse last cnt, because all query time is ordered by time.
 *
 */
#include <algorithm>
#include <iostream>
#include <vector>
#include <cstring>
#include <string>
#include <map>
using namespace std;
struct Record {
    string id;
    int h, m, s, time, status;
};
int main() {
    int n, k, max_time = -1, lastidx = 0, cnt = 0;
    cin >> n >> k;
    vector<Record> rcs(n), prcs; // record array
    map<string, int> ts; // time array
    for (int i = 0; i < n; i++) {
        auto &rc = rcs[i];
        char id[10], status[10];
        scanf("%s %d:%d:%d %s", id, &rc.h, &rc.m, &rc.s, status);
        rc.time = rc.h * 3600 + rc.m * 60 + rc.s;
        rc.id = string(id);
        rc.status = strcmp(status, "in") == 0 ? 1 : -1;
    }
    sort(rcs.begin(), rcs.end(), [](auto &lhs, auto &rhs) {
            return lhs.id != rhs.id ? lhs.id < rhs.id : lhs.time < rhs.time;
            });
    for (int i = 0; i < n - 1; i++) {
        if (rcs[i].id == rcs[i+1].id
                && rcs[i].status == 1 && rcs[i + 1].status == -1) {
            prcs.push_back(rcs[i]);
            prcs.push_back(rcs[i + 1]);
            ts[rcs[i].id] += rcs[i + 1].time - rcs[i].time;
            max_time = max(max_time, ts[rcs[i].id]);
        }
    }
    sort(prcs.begin(), prcs.end(), [](auto &lhs, auto &rhs) {
            return lhs.time < rhs.time;
            });
    for (int i = 0; i < k; i++) {
        int cur_time, h, m, s;
        scanf("%d:%d:%d", &h, &m, &s);
        cur_time = h * 3600 + m * 60 + s;
        int j = lastidx;
        while (j < prcs.size() && prcs[j].time <= cur_time) {
            cnt += prcs[j].status;
            j++;
        }
        lastidx = j;
        printf("%d\n", cnt);
    }
    for (auto ct : ts) {
        if (ct.second == max_time) printf("%s ", ct.first.c_str());
    }
    printf("%02d:%02d:%02d", max_time / 3600, (max_time % 3600) / 60, max_time % 60);
    return 0;
}

