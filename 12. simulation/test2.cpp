#include <iostream>
#include <vector>
using namespace std;

vector<vector<vector<int>>> v;

void rotate(int idx) {
  auto stc = v[idx];
  vector<vector<int>> temp_stc;
  int stc_size = stc.size();
  int stc_elem_size = stc[0].size();

  for (int i = 0; i < 2; i++) {
    vector<int> line;
    for (int j = 0; j < 5; j++) {
      line.push_back(stc[5 - j - 1][i]);
      cout << stc[5 - j - 1][i] << ' ';
    }
    temp_stc.push_back(line);
    cout << '\n';
  }
  v[idx] = temp_stc;

  // for (int i = 0; i < v[idx].size(); i++) {
  //   for (int j = 0; j < v[idx][0].size(); j++) {
  //     cout << v[idx][i][j] << ' ';
  //   }
  //   cout << '\n';
  // }
}
int main(void) {
  vector<vector<int>> stc;
  for (int i = 0; i < 5; i++) {
    vector<int> line;
    for (int j = 0; j < 2; j++) {
      line.push_back(1);
    }
    stc.push_back(line);
  }
  v.push_back(stc);
  rotate(0);
  rotate(0);
}