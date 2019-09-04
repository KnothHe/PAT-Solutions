/*
 * Reference:
 *  https://www.liuchuo.net/archives/2113
 */
#include <vector>
#include <cstdio>
using namespace std;
const int MAX_N = 100005;
struct Node {
    int next;
    bool flag = false;
};
vector<Node> nodes(MAX_N);
int main() {
    int a1, a2, n, add, next;
    char data;
    scanf("%d %d %d", &a1, &a2, &n);
    for (int i = 0; i < n; i++) {
        scanf("%d %c %d", &add, &data, &next);
        nodes[add].next = next;
    }
    for (int i = a1; i != -1; i = nodes[i].next) {
        nodes[i].flag = true;
    }
    for (int i = a2; i != -1; i = nodes[i].next) {
        if (nodes[i].flag) {
            printf("%05d", i);
            return 0;
        }
    }
    printf("-1");
    return 0;
}
