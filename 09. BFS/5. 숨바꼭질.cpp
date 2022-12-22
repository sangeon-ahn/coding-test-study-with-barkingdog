#include <iostream>
#include <queue>
using namespace std;

int board[200001];
int timed[200001];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int N, K;
  cin >> N >> K;
  fill(timed, timed+200000, -1);
  timed[N] = 0;
  queue<int> Q;
  Q.push(N);
  
  while (timed[K] == -1) {
    auto q = Q.front(); Q.pop();
    for (int i = 0; i < 3; i++) {
      int k;
      if (i == 0) {
        k = q - 1;
      }
      if (i == 1) {
        k = q + 1;
      }
      if (i == 2) {
        k = 2 * q;
      }
      if (k < 0 || k > 100000 || timed[k] != -1) continue;
      timed[k] = timed[q] + 1;
      Q.push(k);
    }
  }
  cout << timed[K];
}

// int dist[100002];
// int n,k;
// int main(void){
//   ios::sync_with_stdio(0);
//   cin.tie(0);
//   cin >> n >> k;
//   fill(dist, dist+100001,-1);
//   dist[n] = 0;
//   queue<int> Q;
//   Q.push(n);
//   while(dist[k] == -1){
//     int cur = Q.front(); Q.pop();
//     for(int nxt : {cur-1, cur+1, 2*cur}){
//       if(nxt < 0 || nxt > 100000) continue;
//       if(dist[nxt] != -1) continue;
//       dist[nxt] = dist[cur]+1;
//       Q.push(nxt);
//     }        
//   }
//   cout << dist[k];
// }