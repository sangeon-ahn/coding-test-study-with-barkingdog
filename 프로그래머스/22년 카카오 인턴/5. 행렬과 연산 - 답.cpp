#include <string>
#include <vector>
#include <deque>
using namespace std;

int N, M;

vector<vector<int>> solution(vector<vector<int>> rc, vector<string> operations) {
    deque<int> left_queue;
    deque<int> right_queue;

    deque<deque<int>*> dq;
    N = rc.size(), M = rc[0].size();

    left_queue.assign(N, 0);
    right_queue.assign(N, 0);

    for (int i = 0; i < N; i++)
        dq.push_back(new deque<int>(M - 2)); // 가로줄 - 2 크기의 데큐를 세로줄만큼 삽입.

    for (int i = 0; i < N; i++) {
        left_queue[i] = rc[i][0]; // rc의 첫번째 컬럼.
        right_queue[i] = rc[i][M - 1]; // rc의 마지막 컬럼.
        for (int j = 1; j < M - 1; j++)
            dq[i]->at(j - 1) = rc[i][j];
     }

    for (string s : operations) {
        if (s[0] == 'S') {
            dq.push_front(dq.back()); dq.pop_back();
            left_queue.push_front(left_queue.back()); left_queue.pop_back();
            right_queue.push_front(right_queue.back()); right_queue.pop_back();
        } else {
            dq[0]->push_front(left_queue.front()); left_queue.pop_front();
            right_queue.push_front(dq[0]->back()); dq[0]->pop_back();
            dq[N - 1]->push_back(right_queue.back()); right_queue.pop_back();
            left_queue.push_back(dq[N - 1]->front()); dq[N - 1]->pop_front();
        }
    }

    for(int i = 0; i < N; i++) {
        rc[i][0] = left_queue[i];
        rc[i][M - 1] = right_queue[i];
        for(int j = 1; j < M - 1; j++) rc[i][j] = dq[i]->at(j-1);
    }
    return rc;
}