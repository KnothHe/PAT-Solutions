#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int main()
{
    const int SERVER_TIME = 9*60;
    int N, M, K, Q;
    cin >> N >> M >> K >> Q;
    vector<int> trans_time(K);
    for (int i = 0; i < K; i++) {
        cin >> trans_time[i];
    }
    vector<int> que_time(N, 0);
    vector<int> leave_time(K, 0);
    vector<queue<int>> process(N, queue<int>());
    int customer = 0;
    for (int i = 0; customer < N*M && customer < K; customer++) {
        process[i].push(customer);
        leave_time[customer] = que_time[i] + trans_time[customer];
        que_time[i] = leave_time[customer];
        i = (i + 1) % N;
    }
    int min_index, min_time;
    while (customer < K) {
        min_index = 0;
        min_time = leave_time[process[0].front()];
        for (int i = 1; i < N; i++) {
            int temp = process[i].front();
            if (leave_time[temp] < min_time) {
                min_time = leave_time[temp];
                min_index = i;
            }
        }
        leave_time[customer] = que_time[min_index] + trans_time[customer];
        que_time[min_index] = leave_time[customer];
        process[min_index].pop();
        process[min_index].push(customer);
        customer++;
    }
    // query
    int q;
    for (int i = 0; i < Q; i++) {
        cin >> q;
        if (q <= K) {
            int time = leave_time[q-1];
            if (time - trans_time[q-1] < SERVER_TIME) {
                printf("%02d:%02d\n", time / 60 + 8, time % 60);
            } else {
                printf("Sorry\n");
            }
        }
    }
    return 0;
}

