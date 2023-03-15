#include <bits/stdc++.h>
using namespace std;

long long plays[360010];
long long sums[360010];

int convertToSec(string time) {
    int result = 0;
    int hour = stoi(time.substr(0, 2));
    int minute = stoi(time.substr(3, 2));
    int second = stoi(time.substr(6, 2));
    
    result += hour * 60 * 60 + minute * 60 + second;
    
    return result;
}

vector<string> split(string str, char delimiter) {
    stringstream ss(str);
    string temp;
    vector<string> result;
    
    while (getline(ss, temp, delimiter)) {
        result.push_back(temp);
    }
    
    return result;
}

// 확인완
string toStr(int time) {
    if (time < 10) {
        return "0" + to_string(time);
    }
    return to_string(time);
}

string secToString(int sec) {
    int hour = sec / 3600;
    int minute = (sec - hour * 3600) / 60;
    int second = sec - hour * 3600 - minute * 60;
    
    return toStr(hour) + ":" + toStr(minute) + ":" + toStr(second);
}
string solution(string play_time, string adv_time, vector<string> logs) {
    string answer = "";
    int advTime = convertToSec(adv_time);
    int playTime = convertToSec(play_time);
    
    for (int i = 0; i < logs.size(); i++) {
        vector<string> playDuration = split(logs[i], '-');
        
        int startTime = convertToSec(playDuration[0]);
        int endTime = convertToSec(playDuration[1]);
      
        for (int i = startTime; i <= endTime; i++) {
            plays[i]++;
        }
    }
    // 합 배열 구하기
    // sums[k] = sums[k - 1] + plays[k]
    sums[0] = plays[0];
    
    for (int i = 1; i <= playTime; i++) {
        sums[i] = sums[i - 1] + plays[i];
    }
    
    long long maxPlayTime = sums[advTime];
    int insertedTime = 0;
    
    for (int i = 1; i < playTime; i++) {
        if (advTime + i > playTime) break;
        if (maxPlayTime < sums[i + advTime] - sums[i - 1]) {
            maxPlayTime = sums[i + advTime] - sums[i - 1];
            insertedTime = i;
        }
    }
    
    answer = secToString(insertedTime);
    return answer;
}