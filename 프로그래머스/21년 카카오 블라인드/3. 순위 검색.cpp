#include <bits/stdc++.h>
using namespace std;
// 2시간 30분 소요
vector<int> tree[50];
vector<int> scores[100];
map<string, int> orders;

vector<string> split(string str, char delimiter) {
    vector<string> result;
    stringstream ss(str);
    string temp;

    while (getline(ss, temp, delimiter)) {
        if (temp == "and") continue;
        result.push_back(temp);
    }

    return result;
}

vector<int> solution(vector<string> info, vector<string> query) {
    vector<int> answer;

    // 트리 만들기
    tree[0].push_back(1);
    tree[0].push_back(2);
    tree[0].push_back(3);

    for (int i = 1; i <= 21; i++) {
        tree[i].push_back(i * 2 + 2);
        tree[i].push_back(i * 2 + 3);
    }

    // orders에 순서 넣기
    orders["cpp"] = 0;
    orders["java"] = 1;
    orders["python"] = 2;
    orders["backend"] = 0;
    orders["frontend"] = 1;
    orders["junior"] = 0;
    orders["senior"] = 1;
    orders["chicken"] = 0;
    orders["pizza"] = 1;

    // info 노드 추출후 점수 삽입
    for (int i = 0; i < info.size(); i++) {
        vector<string> inf = split(info[i], ' ');

        int node_num = 0;
        if (inf[0] == "cpp") node_num = 1;
        else if (inf[0] == "java") node_num = 2;
        else node_num = 3;

        if (inf[1] == "backend") node_num = 2 * node_num + 2;
        else node_num = node_num * 2 + 3;

        if (inf[2] == "junior") node_num = node_num * 2 + 2;
        else node_num = node_num * 2 + 3;

        if (inf[3] == "chicken") node_num = node_num * 2 + 2;
        else node_num = node_num * 2 + 3;

        scores[node_num].push_back(stoi(inf[4]));
    }
    
    for (int i = 0; i < 50; i++) {
        if (scores[i].size() == 0) continue;
        else sort(scores[i].begin(), scores[i].end());
    }

    // 조건, 현재노드, 몇층인지
    queue<pair<vector<string>, pair<int, int>>> q;

    for (int i = 0; i < query.size(); i++) {
        int result = 0;
        vector<string> qry = split(query[i], ' ');

        q.push({qry, {0, 0}});

        while (!q.empty()) {
            auto p = q.front(); q.pop();
            vector<string> cond = p.first;
            int curr_node = p.second.first;
            int curr_layer = p.second.second;

            // 리프노드면 점수 확인
            if (curr_layer == 4) {
                auto it = lower_bound(scores[curr_node].begin(), scores[curr_node].end(), stoi(cond[4]));
                result += scores[curr_node].end() - it;     
            }

            // 해당 층 조건이 - 이면 전부 넣기
            else if (cond[curr_layer] == "-") {
                for (auto next_p : tree[curr_node]) {
                    q.push({qry, {next_p, curr_layer + 1}});
                }
            }

            // -이 아니면 해당 조건만 넣기
            else if (cond[curr_layer] != "-") {
                q.push({qry, {tree[curr_node][orders[cond[curr_layer]]], curr_layer + 1}});
            }
        }

        answer.push_back(result);
    }

    return answer;
}