#include <string>
#include <vector>
#include <map>
#include <set>
#include <iostream>
using namespace std;
// 좌석이 시소 중심에서 2, 3, 4m 떨어진 곳에 있다.
const int ratio[3] = { 2, 3, 4 };

const int divider[3] = { 1, 2, 3 };

long long solution(vector<int> weights) {
    int idx = 0;
    long long answer = 0;
    
    // 무게 중복제외하고 저장할 Set
    set<int> weightSet;

    // 특정 무게가 몇 번 나왔는지 저장하는 Map
    map<int, int> weight2cnt;
    
    // Set과 Map 저장
    for (int weight : weights)
    {
        weightSet.insert(weight);
        weight2cnt[weight]++;
    }
    
    for (int weight : weightSet)
    {
        // 특정 무게가 n명 있으면 n명 중 2명 뽑으면 되므로 nC2를 답에 추가.
        long long weightSize = weight2cnt[weight];
        answer += (weightSize * (weightSize - 1)) / 2;
        
        // 
        for (int i = 0; i < 3; i++)
        {
            // 나머지가 0이 아니면 패스.
            // 패스하는 이유는 비례식을 세울 수 없는 수이기 때문이다.
            if (weight % divider[i])
            {
                continue;
            }
            
            // 나머지가 0이면 계산 수행.
            // A:B = 2:3, 3:4, 2:4 이므로 1:2, 2:3, 3:4 인 경우를 찾으면 되는데,
            // 비례식을 계산하면 B = 3A / 2, 4A / 3, 2A / 1 이므로 총 3번 확인하면 된다.
            int calculatedWeight = (weight / divider[i]) * ratio[i];

            // 해당 무게의 개수를 구한 후,
            long long size = weight2cnt[calculatedWeight];

            // A 무게의 개수 x B 무게의 개수를 더하면 된다.. 형변환을 위해 1LL을 곱해준다.
            answer += weightSize * size * 1LL;
        }
    }
    
    return answer;
}