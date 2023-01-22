#include <iostream>
#include <vector>
using namespace std;

vector<vector<vector<int>>> v;
int board[100][100];
int N, M, K;

void rotate(int idx) {
  auto stc = v[idx];
  vector<vector<int>> temp_stc;
  for (int i = 0; i < stc[0].size(); i++) {
    vector<int> line;
    for (int j = 0; j < stc.size(); j++) {
      line.push_back(stc[stc.size() - j - 1][i]);
    }
    temp_stc.push_back(line);
  }
  v[idx] = temp_stc;

  // for (int i = 0; i < v[idx].size(); i++) {
  //   for (int j = 0; j < v[idx][0].size(); j++) {
  //     cout << v[idx][i][j] << ' ';
  //   }
  //   cout << '\n';
  // }
}

bool check_and_paste(int idx) {
  auto stc = v[idx];
  int x_size = stc.size();
  int y_size = stc[0].size();

  int x_move = N - x_size;
  int y_move = M - y_size;
  
  for (int i = 0; i <= x_move; i++) {
    for (int j = 0; j <= y_move; j++) {
      int isvalid = true;

      for (int k = 0; k < x_size; k++) {
        for (int m = 0; m < y_size; m++) {
          if (stc[k][m] == 1) {
            if (board[k+i][m+j] == 1) {
              isvalid = false;
            }
          }
        }
      }

      if (isvalid) {
        for (int x = 0; x < x_size; x++) {
          for (int y = 0; y < y_size; y++) {
            if (stc[x][y] == 1) {
              board[x+i][y+j] = stc[x][y];
            }
          }
        }
        return true;
      }
    }
  }
  return false;
}

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> N >> M >> K;

  for (int i = 0; i < K; i++) {
    int a, b;
    cin >> a >> b;
    vector<vector<int>> sticker;

    for (int i = 0; i < a; i++) {
      vector<int> line;
      for (int j = 0; j < b; j++) {
        int p;
        cin >> p;
        line.push_back(p);
      }
      sticker.push_back(line);
    }
    v.push_back(sticker);
  }

  for (int i = 0; i < v.size(); i++) {
    int count = 0;

    while (count < 4) {
      if (check_and_paste(i)) {
        break;
      } else {
        rotate(i);
        count++;
      }
    }
  }
  int ans = 0;

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      if (board[i][j] == 1) {
        ans++;
      }
    }
  }
  cout << ans;
}