#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
using namespace std;
struct Record {
    int arr_time, pro_time;
};
int main()
{
    const int beg_time = 8 * 60 * 60;
    const int end_time = 17 * 60 * 60;
    int N, K;
    cin >> N >> K;
    vector<Record> records;
    for (int i = 0; i < N; i++) {
        Record r;
        int h, m, s, p;
        scanf("%d:%d:%d %d", &h, &m, &s, &p);
        r = {h * 60 * 60 + m * 60 + s, p * 60};
        if (r.arr_time <= end_time) {
            records.push_back(r);
        }
    }
    sort(records.begin(), records.end(), [](const Record &lhs, const Record &rhs) {
            return lhs.arr_time < rhs.arr_time;
            });
    vector<int> window(K, beg_time);
    int total = 0;
    for (int i = 0; i < records.size(); i++) {
        int min = 0;
        for (int j = 1; j < K; j++) {
            if (window[j] < window[min]) {
                min = j;
            }
        }
        if (records[i].arr_time < window[min]) {
            total += window[min] - records[i].arr_time;
            window[min] += records[i].pro_time;
        } else {
            window[min] = records[i].arr_time + records[i].pro_time;
        }
    }
    if (records.size() == 0) {
        printf("0.0");
    } else {
        printf("%.1lf\n", total / 60.0 / records.size());
    }
    return 0;
}

