#include <bits/stdc++.h>

using namespace std;
/*
    우선 parent배열로 해당 노드의 부모를 체크하고 graph배열에 해당 노드의 자식을 넣는다.
    그리고 자식을 오름차순 정렬한다.
    길 정보를 나타내는 배열을 만들고 간선 이동시마다 갱신한다.
    우선 길을 따라 리프노드까지 내려갔을 때 해당 리프노드의 target값을 확인한다.
    이렇게 어떤 리프가 선택될지 다 알았으면 이제 제일 길이가 짧도록 한다.
    한번에 처리할 수 있다 => 바로 처리
    두번 해야한다 => 1, 3,  2, 3,  3, 3
    일단 각 노드별로 최대로 넣을 수 있는 숫자 구하고 타겟들 다 채웠을 때 각 노드들은 숫자를 오름차순 정렬 한다. 그리고 배치한다. 각 노드별로 배치되야 하는 인덱스 정보도 따로 저장해뒀다가 사용한다.
*/

int parent[101];
int routes[101];

vector<int> graph[101];
vector<int> Target;
vector<vector<int>> locations;
vector<vector<int>> numbers;

bool target_all_clear() {
    for (int i = 0; i < Target.size(); i++) {
        if (Target[i] != 0) return false;
    }
    return true;
}

void changeRoute(int node) {
    vector<int> children = graph[node];
    int curRoute = routes[node];

    if (children.size() == 1) return;
    else if (children[children.size() - 1] == curRoute) routes[node] = children[0];
    else {
        for (int i = 0; i < children.size(); i++) {
            if (children[i] == curRoute) {
                routes[node] = children[i + 1];
                return;
            }
        }
    }
}

vector<int> solution(vector<vector<int>> edges, vector<int> target) {
    vector<int> answer;
    Target = target;

    for (vector<int> edge : edges) {
        int p = edge[0];
        int c = edge[1];

        graph[p].push_back(c);
    }

    // 자식들 오름차순 정렬, 길 설정
    for (int i = 1; i <= 100; i++) {
        if (graph[i].size() != 0) {
            sort(graph[i].begin(), graph[i].end());
            routes[i] = graph[i][0];
        }
    }

    // 길 따라가기
    int node = 1;
    int count = 0;
    while (!target_all_clear()) {
        int route = routes[node];
        changeRoute(node);
        node = route;

        // 해당 루트로 가서 도착한 노드가 리프노드면
        if (graph[node].empty()) {
            int number = 1;

            // 남은 타겟값 확인 후 떨어뜨릴 숫자 구하기
            if (Target[node] > 3) {
                number = 3;
                Target[node] -= 3;
            } else if (Target[node] > 0) {
                number = Target[node];
                Target[node] = 0;
            } else {
                return {-1};
            }
            // locations는 노드별로 어떤 값이 몇번째에 떨어졌는지를 넣는 곳
            locations[node].push_back(count);
            numbers[node].push_back(number);
            count++;

            // 다시 node = 1 시키고 돌기
            node = 1;
        }
    }

    // numbers를 오름차순 정렬
    for (int i = 1; i <= numbers.size(); i++) {
        if (numbers[i].size() <= 1) continue;

        sort(numbers[i].begin(), numbers[i].end());
        sort(locations[i].begin(), locations[i].end());
    }

    // locations에 끼워맞추기
    for (int i = 1; i <= locations.size(); i++) {
        // ex) locations[1] = {0, 3, 5}, numbers[1] = {1, 2, 3}이면
        // answer[0] = 1, answer[3] = 2, answer[5] = 3;
        vector<int> location = locations[i];
        if (location.empty()) continue;

        for (int j = 0; j < location.size(); j++) {
            answer[location[j]] = numbers[i][j];
        }
    }

    return answer;
}