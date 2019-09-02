/*
 * references:
 *  https://oliverlew.github.io/PAT/Advanced/1016.html
 *  https://www.liuchuo.net/archives/2350
 */
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <string>
#include <cstdio>
using namespace std;
class Record {
public:
    string  name;
    int month, day, hour, minute, time, state;
     
    double billFromZero(vector<int> &tolls) {
        long total = tolls[hour] * minute + tolls[24] * 60 * day;
        for (int i = 0; i < hour; i++) {
            total += tolls[i] * 60;
        }
        return total / 100.0;
    }
};
bool cmp(const Record &lhs, const Record &rhs) {
    return lhs.name != rhs.name ? lhs.name < rhs.name : lhs.time < rhs.time;
}
int main()
{
    string state;
    vector<int> tolls(25, 0);
    int N;
    for (int i = 0; i < 24; i++) {
        cin >> tolls[i];
        tolls[24] += tolls[i];
    }
    cin >> N;
    vector<Record> records(N);
    for (int i = 0; i < N; i++) {
        Record &r = records[i];
        cin >> r.name;
        scanf("%d:%d:%d:%d", &r.month, &r.day, &r.hour, &r.minute);
        cin >> state;
        r.state = (state == "on-line" ? 1 : 0);
        r.time = r.day * 24 * 60 + r.hour * 60 + r.minute;
    }
    sort(records.begin(), records.end(), cmp);
    map<string, vector<Record>> items;
    for (int i = 1; i < N; i++) {
        if (records[i - 1].name == records[i].name &&
                records[i - 1].state == 1 && 
                records[i].state == 0) {
            string name = records[i].name;
            items[name].push_back(records[i - 1]);
            items[name].push_back(records[i]);
        }
    }
    for (auto &it : items) {
        vector<Record> &r = it.second;
        cout << it.first;
        printf(" %02d\n", r[0].month);
        double total = 0.0;
        for (int i = 1; i < r.size(); i += 2) {
            double t = r[i].billFromZero(tolls) - r[i - 1].billFromZero(tolls);
            printf("%02d:%02d:%02d %02d:%02d:%02d %d $%.2lf\n",
                    r[i - 1].day, r[i - 1].hour, r[i - 1].minute, 
                    r[i].day, r[i].hour, r[i].minute, r[i].time - r[i - 1].time, t);
            total += t;
        }
        printf("Total amount: $%.2lf\n", total);
    }
    return 0;
}
