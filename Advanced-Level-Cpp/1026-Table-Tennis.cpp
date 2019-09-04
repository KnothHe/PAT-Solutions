/*
 * Reference:
 *  https://www.liuchuo.net/archives/2955
 */
#include <algorithm>
#include <vector>
#include <cstdio>
using namespace std;
const int BEG_TIME =  8 * 3600;
const int END_TIME = 21 * 3600;
struct Person {
    int arrive, serve = END_TIME, play;
    bool vip;
} person;
struct Table {
    int end = BEG_TIME, num;
    bool vip;
};
vector<Person> players;
vector<Table> tables;
void allocTable(int person_id, int table_id) {
    if (players[person_id].arrive <= tables[table_id].end) {
        players[person_id].serve = tables[table_id].end;
    } else {
        players[person_id].serve = players[person_id].arrive;
    }
    tables[table_id].end = players[person_id].serve + players[person_id].play;
    tables[table_id].num++;
}
int findNextVip(int vip_id) {
    vip_id++;
    while (vip_id < players.size() && !players[vip_id].vip) vip_id++;
    return vip_id;
}
int main() {
    int N, K, M, vip_table;
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        int h, m, s, play, flag;
        scanf("%d:%d:%d %d %d", &h, &m, &s, &play, &flag);
        person.arrive = h * 3600 + m * 60 + s;
        if (person.arrive >= END_TIME) continue;
        person.play = play <= 120 ? play * 60 : 7200;
        person.vip = flag == 1;
        players.push_back(person);
    }
    scanf("%d %d", &K, &M);
    tables.resize(K + 1);
    for (int i = 0; i < M; i++) {
        scanf("%d", &vip_table);
        tables[vip_table].vip = true;
    }
    sort(players.begin(), players.end(), [](auto &lhs, auto &rhs) {
            return lhs.arrive < rhs.arrive;
            });
    int i = 0, vip_id = findNextVip(-1);
    while (i < players.size()) {
        int index = 1;
        for (int j = 2; j <= K; j++) {
            if (tables[j].end < tables[index].end) {
                index = j;
            }
        }
        if (tables[index].end >= END_TIME) break;
        if (players[i].vip && i < vip_id) {
            i++; continue;
        }
        if (tables[index].vip) {
            if (players[i].vip) {
                allocTable(i, index);
                vip_id = findNextVip(vip_id);
                i++;
            } else {
                if (vip_id < players.size() && 
                        players[vip_id].arrive <= tables[index].end) {
                    allocTable(vip_id, index);
                    vip_id = findNextVip(vip_id);
                } else {
                    allocTable(i, index);
                    i++;
                }
            }
        } else {
            if (!players[i].vip) {
                allocTable(i, index);
                i++;
            } else {
                int vip_index = -1, min_vip_end = 1 << 30;
                for (int j = 1; j <= K; j++) {
                    if (tables[j].vip && tables[j].end < min_vip_end) {
                        min_vip_end = tables[j].end;
                        vip_index = j;
                    }
                }
                if (vip_index != -1 && players[i].arrive >= tables[vip_index].end) {
                    allocTable(vip_id, vip_index);
                } else {
                    allocTable(i, index);
                }
                vip_id = findNextVip(vip_id);
                i++;
            }
        }
    }
    sort(players.begin(), players.end(), [](auto &lhs, auto &rhs) {
            return lhs.serve < rhs.serve;
            });
    for (auto &p : players) {
        if (p.serve >= END_TIME) break;
        printf("%02d:%02d:%02d %02d:%02d:%02d %d\n",
                p.arrive / 3600, p.arrive % 3600 / 60, p.arrive % 60,
                p.serve / 3600, p.serve % 3600 / 60, p.serve % 60,
                (p.serve - p.arrive + 30) / 60);
    }
    for (i = 1; i <= K; i++) {
        if (i != 1) printf(" ");
        printf("%d", tables[i].num);
    }
    return 0;
}

