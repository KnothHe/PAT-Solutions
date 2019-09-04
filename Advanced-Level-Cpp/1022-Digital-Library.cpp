#include <iostream>
#include <sstream>
#include <map>
#include <set>
using namespace std;
void query(map<string, set<int>> &m, string &q) {
    if (m.find(q) != m.end()) {
        for (int item : m[q]) {
            printf("%07d\n", item);
        }
    } else {
        printf("Not Found\n");
    }
}
int main() {
    int n, m;
    map<string, set<int>> title, author, key, publisher, year;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int id;
        string str, keyword;
        scanf("%d\n", &id);
        getline(cin, str);
        title[str].insert(id);
        getline(cin, str);
        author[str].insert(id);
        getline(cin, str);
        istringstream iss(str);
        while (iss >> keyword) {
            key[keyword].insert(id);
        }
        getline(cin, str);
        publisher[str].insert(id);
        getline(cin, str);
        year[str].insert(id);
    }
    cin >> m;
    for (int i = 0; i < m; i++) {
        int type;
        string str;
        scanf("%d: ", &type);
        getline(cin, str);
        printf("%d: %s\n", type, str.c_str());
        switch (type) {
            case 1 : query(title, str); break;
            case 2 : query(author, str); break;
            case 3 : query(key, str); break;
            case 4 : query(publisher, str); break;
            case 5 : query(year, str); break;
        }
    }
    return 0;
}

