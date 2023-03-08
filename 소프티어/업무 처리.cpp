#include <bits/stdc++.h>
using namespace std;

vector<int> tree[2000];
queue<int> leftQ[2000];
queue<int> rightQ[2000];
int parent[2000];

int done;
queue<int> works[2000];

void solve(int R) {
	queue<int> q;
	int day = 1;

	while (day <= R) {
		// cout << day << '\n';
		q.push(0);

		while (!q.empty()) {
			int n = q.front(); q.pop();

			// 부서장이면 일 완료하기
			if (n == 0) {
				if (day % 2 == 0 && !rightQ[n].empty()) {
			
					done += rightQ[n].front();
					rightQ[n].pop();
				}
				else if (day % 2 != 0 && !leftQ[n].empty()) {
					cout << "HI2";
					done += leftQ[n].front();
					leftQ[n].pop();
				}
			}

			for (int new_n : tree[n]) {
				// cout << new_n << ' ';
				// 말단 아니면 홀짝 맞춰서 부모노드에 일 올리기
				if (tree[new_n].size()) {
				
					// 짝수날이면
					if (day % 2 == 0) {
						// 부모 노드의 왼쪽 자식이면 new_n의 오른쪽 노드에 있는걸 부모의 왼쪽 큐에 넣는다. 
						if (n * 2 + 1 == new_n && !rightQ[new_n].empty()) {
							leftQ[n].push(rightQ[new_n].front());
							rightQ[new_n].pop();
						}
						// 오른쪽 자식이면 new_n의 오른쪽 노드에 있는걸 부모의 오른쪽 큐에 넣는다.
						else if (n * 2 + 2 == new_n && !rightQ[new_n].empty()) {
							rightQ[n].push(rightQ[new_n].front());
							rightQ[new_n].pop();
						}
					}
					// 홀수날이면
					else {
						// 부모 노드의 왼쪽 자식이면 new_n의 왼쪽 큐에 있는걸 부모의 왼쪽 큐에 넣는다.
						if (n * 2 + 1 == new_n && !leftQ[new_n].empty()) {
							leftQ[n].push(leftQ[new_n].front());
							leftQ[new_n].pop();
						}

						// 오른쪽 자식이면 new_n의 왼쪽에 있는걸 부모의 오른쪽에 넣는다.
						else if (n * 2 + 2 == new_n && !leftQ[new_n].empty()) {
							rightQ[n].push(leftQ[new_n].front());
							leftQ[new_n].pop();
						}
					}

					q.push(new_n);
				}

				// 말단이면 부모노드에 일 올리기
				else {
					// 왼쪽 말단인 경우 부모의 왼쪽 큐에 넣기
					if (n * 2 + 1 == new_n && !works[new_n].empty()) {
						leftQ[n].push(works[new_n].front());
						works[new_n].pop();
					}
					// 오른쪽 말단인 경우 부모의 오른쪽 큐에 넣기
					else if (n * 2 + 2 == new_n && !works[new_n].empty()) {
						rightQ[n].push(works[new_n].front());
						works[new_n].pop();
					}
				}
			}
		}
		day++;
	}
	
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int H, K, R;
	cin >> H >> K >> R;

	for (int i = 0; i < pow(2, H) - 1; i++) {
		tree[i].push_back(2 * i + 1);
		tree[i].push_back(2 * i + 2);
		parent[2 * i + 1] = i;
		parent[2 * i + 2] = i;
	}

	// 말단 일 채우기
	for (int i = 0; i < pow(2, H); i++) {
		for (int j = 0; j < K; j++) {
			int a;
			cin >> a;
			int x = pow(2, H);
			works[i + x - 1].push(a);
		}
	}

	solve(R);

	cout << done;
}