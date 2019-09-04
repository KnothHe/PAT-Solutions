/*
 * Simple dfs.
 *
 */
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <climits>
using namespace std;
int n, k, t, gcost = INT_MAX, ghap = INT_MIN;
int lcn = 0; // number of different routes with least cost !!! NOTE
vector<int> gpath;
vector<bool> mark;
vector<vector<int>> gp;
map<int, int> haps;
map<int, string> city;
map<string, int> city_index;
void dfs(int cur, int tcost, int thap, vector<int> &tpath) {
    if (city[cur] == "ROM") {
        if (tcost < gcost) {
            gcost = tcost;
            ghap = thap;
            gpath = tpath;
            lcn = 1;
        } else if (tcost == gcost) {
            lcn++;
            if (thap > ghap) {
                ghap = thap;
                gpath = tpath;
            } else if (thap == ghap) {
                if (tpath.size() < gpath.size()) {
                    gpath = tpath;
                }
            }
        }
        return;
    }
    for (int i = 1; i < n; i++) {
        if (!mark[i] && gp[cur][i] != INT_MAX) {
            mark[i] = true;
            tpath.push_back(i);
            dfs(i, tcost + gp[cur][i], thap + haps[i], tpath);
            mark[i] = false;
            tpath.pop_back();
        }
    }
}
int main() {
    string c, c1, c2;
    cin >> n >> k >> c;
    gp.resize(n, vector<int>(n, INT_MAX));
    city[0] = c;
    city_index[c] = 0;
    haps[0] = 0;
    for (int i = 1; i < n; i++) {
        cin >> c >> t;
        haps[i] = t;
        city[i] = c;
        city_index[c] = i;
    }
    for (int i = 0; i < k; i++) {
        cin >> c1 >> c2 >> t;    
        int c1i = city_index[c1], c2i = city_index[c2];
        gp[c1i][c2i] = gp[c2i][c1i] = t;
    }
    mark.resize(n, false);
    vector<int> tpath;
    tpath.push_back(0);
    dfs(0, 0, 0, tpath);
    cout << lcn << " " << gcost << " " 
        << ghap << " " << ghap / (gpath.size() - 1) << "\n";
    cout << city[gpath[0]];
    for (int i = 1; i < gpath.size(); i++) { cout << "->" << city[gpath[i]]; }
    return 0;
}

