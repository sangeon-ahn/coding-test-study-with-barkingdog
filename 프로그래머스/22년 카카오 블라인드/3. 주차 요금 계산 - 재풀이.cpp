#include <bits/stdc++.h>

using namespace std;

map<string, bool> isIn;
map<string, int> inTime;
map<string, int> parkingTime;
map<string, int> parkingFees;
set<string> carNums;

int pay(int time, vector<int> fees) {
    cout << time << '\n';
    if (time <= fees[0]) return fees[1];
    int sum = fees[1];
    int remained = time - fees[0];
    int multiply = remained / fees[2];

    if (remained % fees[2] != 0) multiply++;
    sum += fees[3] * multiply;

    return sum;
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

int toInt(string time) {
    int hours = stoi(time.substr(0, 2));
    int minutes = stoi(time.substr(3, 2));

    return hours * 60 + minutes;
}

vector<int> solution(vector<int> fees, vector<string> records) {
    vector<int> answer;

    for (string record : records) {
        vector<string> rec = split(record, ' ');
        string time = rec[0];
        string carNum = rec[1];

        carNums.insert(carNum);

        if (rec[2] == "IN") {
            isIn[carNum] = true;
            inTime[carNum] = toInt(time);
        }
        else if (rec[2] == "OUT") {
            if (isIn[carNum]) {
                parkingTime[carNum] += toInt(time) - inTime[carNum];
                isIn[carNum] = false;
                inTime[carNum] = 0;
            }
        }
    }


    vector<string> vec(carNums.begin(), carNums.end());
    sort(vec.begin(), vec.end());

    // 시간 계산 & 요금 계산
    for (string carNum : vec) {
        if (isIn[carNum]) {
            parkingTime[carNum] += toInt("23:59") - inTime[carNum];
        }

        answer.push_back(pay(parkingTime[carNum], fees));
    }

    return answer;
}