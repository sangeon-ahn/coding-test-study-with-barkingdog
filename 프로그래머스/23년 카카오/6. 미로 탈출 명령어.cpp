#include <string>
#include <vector>

using namespace std;
// n*m 격자 미로, 출발지: (x,y), 도착지: (r,c), 횟수:k
string answer = "z";

int dx[4] = {1, 0, 0, -1};
int dy[4] = {0, -1, 1, 0};
char dir[4] = {'d', 'l', 'r', 'u'};

void dfs(int n, int m, int x, int y, int r, int c, int k, int count, string str) {
    // 남은 거리
    int remained = abs(r - x) + abs(c - y);
    
    // 남은 기회
    int opports = k - count;
    
    // 남은 거리가 남은 기회보다 크면 리턴
    if (remained > opports) return;
    
    // 도착했으면 answer와 비교후 더 사전순으로 앞에 있으면 교체
    if (x == r && y == c && k == count && str < answer) {
        answer = str;
        return;
    }
    
    // 아직 더 가야하는 경우
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        
        if (nx >= 1 && nx <= n && ny >= 1 && ny <= m && str < answer) {
            dfs(n, m, nx, ny, r, c, k, count + 1, str + dir[i]);    
        }
        
    }
}

string solution(int n, int m, int x, int y, int r, int c, int k) {
    // 거리 자체가 k보다 크면 impossible
    int dist = abs(r - x) + abs(c - y);
    if (dist > k) return "impossible";
    
    // 도착지 한칸 전까지 최단거리로 왔는데 남은 거리가 짝수면 impossible
    // ex) k = 5, dist = 2일 때 dist - 1만큼 갔을 때 k - (dist - 1) 이 값이 짝수면 안된다
    if ((k - (dist - 1)) % 2 == 0) return "impossible";
    
    // d, l, r, u 순서로 진행
    dfs(n, m, x, y, r, c, k, 0, "");
    
    return answer;
}