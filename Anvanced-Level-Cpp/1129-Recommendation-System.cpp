#include <iostream>
#include <set>
using namespace std;
int book[50005];
struct Item {
    int id, cnt;
    bool operator<(const Item &o) const {
        return cnt != o.cnt ? cnt > o.cnt : id < o.id;
    }
};
int main() {
    int n, k, t;
    cin >> n >> k;
    set<Item> items;
    for (int i = 0; i < n; i++) {
        cin >> t;
        if (!items.empty()) { cout << t << ":"; }
        int cnt = 0;
        for (auto it = items.begin();
                it != items.end() && cnt < k; it++, cnt++) {
            cout << " " << it->id;
        }
        if (!items.empty()) { cout << "\n"; }
        auto it = items.find({t, book[t]});
        if (it != items.end()) items.erase(it);
        items.insert({t, ++book[t]});
    }
    return 0;
}

