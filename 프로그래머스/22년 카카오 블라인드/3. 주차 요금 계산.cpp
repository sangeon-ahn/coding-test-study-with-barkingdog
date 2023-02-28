#include <bits/stdc++.h>
using namespace std;
/*
    0. 차번호가 담길 set1, in, out 여부 담길 map1, in, out 시간 담길 map2
    1. records를 돈다.
    2. 차번호를 set1에 담는다.
    3.
*/
// 문제 잘못 읽음 => 내일 재풀이.
set<string> carNums;
map<string, bool> isIn;
map<string, int> inTime;
map<string, int> pays;
vector<int> Fees = {180, 5000, 10, 600};

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
    string hour = time.substr(0, 2);
    string minute = time.substr(3, 5);

    return stoi(hour) * 60 + stoi(minute);
}

int calculate(int inTime, int outTime) {
    int sum = 0;
    int diff = outTime - inTime;

    if (diff > Fees[0]) {
        sum += Fees[1];
        diff -= Fees[0];

        if (diff % Fees[2] != 0) {
            sum += (diff / Fees[2] + 1) * Fees[3];
        }
        else sum += ceil(diff / Fees[2]) * Fees[3];

        return sum;
    }

    else return Fees[1];
}

void pay(int outTime, string car) {
    pays[car] += calculate(inTime[car], outTime);
    isIn[car] = false;
}

vector<int> solution(vector<int> fees, vector<string> records) {
    vector<int> answer;
    Fees = fees;

    for (string record : records) {
        vector<string> rec = split(record, ' ');
        carNums.insert(rec[1]);

        if (rec[2] == "IN") {
            isIn[rec[1]] = true;
            inTime[rec[1]] = toInt(rec[0]);
        }

        else if (rec[2] == "OUT") {
            isIn[rec[1]] = false;
            outTime[rec[1]] = toInt(rec[0]);
            // pay(toInt(rec[0]), rec[1]);
        }
    }

    for (string car : carNums) {
        if (isIn[car]) {
            pay(23 * 60 + 59, car);
        }
    }

    vector<string> cars(carNums.begin(), carNums.end());
    sort(cars.begin(), cars.end());

    for (string car : cars) {
        answer.push_back(pays[car]);
    }

    return answer;
}

int main() {
  int fee = calculate(toInt("18:59"), toInt("23:59"));
  cout << fee;
}