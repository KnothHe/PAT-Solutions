/*
 * reference:
 *  https://www.liuchuo.net/archives/2295
 * because I don't konw the correct way to read input.
 */
#include <iostream>
#include <sstream>
#include <string>
#include <map>
#include <set>
using namespace std;
int N, M;
map<string, set<int>> title, author, key, pub, year;
void query(map<string, set<int>> &m, string &str) {
    if (m.find(str) != m.end()) {
        for (const auto &n : m[str]) {
            printf("%07d\n", n);
        }
    } else {
        cout << "Not Found\n";
    }
}
int main()
{
    int id;
    string t_title, t_author, t_keys, t_key, t_pub, t_year;
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        scanf("%d\n", &id);
        getline(cin, t_title);
        title[t_title].insert(id);
        getline(cin, t_author);
        author[t_author].insert(id);
        getline(cin, t_keys);
        istringstream iss(t_keys);
        while (iss >> t_key) {
            key[t_key].insert(id);
        }
        getline(cin, t_pub);
        pub[t_pub].insert(id);
        getline(cin, t_year);
        year[t_year].insert(id);
    }
    scanf("%d", &M);
    for (int i = 0; i < M; i++) {
        int q;
        string str;
        scanf("%d: ", &q);
        getline(cin, str);
        cout << q << ": " << str << endl;
        switch (q) {
            case 1 : query(title, str); break;
            case 2 : query(author, str); break;
            case 3 : query(key, str); break;
            case 4 : query(pub, str); break;
            case 5 : query(year, str); break;
        }
    }
    return 0;
}
