import sys
input = sys.stdin.readline
sys.setrecursionlimit(10**8)

dx = [1, 0, 0, -1]
dy = [0, -1, 1, 0]
dAlpha = ['d', 'l', 'r', 'u']
answer = "z"


def isVaild(nx, ny, n, m):
    return 1 <= nx and nx <= n and 1 <= ny and ny <= m


def dfs(n, m, x, y, r, c, prev_s, cnt, k):
    global answer

    # 현재까지 지나간 만큼에 남은 거리를 더했을 때 k보다 크면 불가능하다.
    if k < cnt + abs(x - r) + abs(y - c):
        return

    # k번째에 목적지에 도착했을 때.
    if x == r and y == c and cnt == k:

        # 새로운 답을 할당하고, 끝내기.
        answer = prev_s
        return
    
    # 아직 기회가 남았고 가능한 상태이기 때문에 상하좌우 네 방향을 본다.
    for i in range(4):

    # 격자 내에 새로운 점이 있고, answer값이 prev_s보다 문자열 오름차순 기준으로 더 클 때, 
        if isVaild(x + dx[i], y + dy[i], n, m) and prev_s < answer:

            # 현재 지점과 문자열과 카운트값을 갱신한 후 다시 dfs
            dfs(n, m, x + dx[i], y + dy[i], r, c, prev_s+dAlpha[i], cnt + 1, k)


def solution(n, m, x, y, r, c, k):
    # 거리를 구한다.
    dist = abs(x - r) + abs(y - c)
    
    # 만약 이미 주어진 k를 초과했거나, 도착했을 때 남은 거리가 홀수개면 불가능한 경우다.
    if dist > k or (k - dist) % 2 == 1:
        return "impossible"

    # 격자크기, 시작점, 목표점, 초기 문자열값, 카운트, k를 넣고 dfs
    dfs(n, m, x, y, r, c, "", 0, k)

    return answer