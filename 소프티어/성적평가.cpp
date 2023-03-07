#include <bits/stdc++.h>
using namespace std;

/*
	대회별로 사람-점수 map으로 매핑 후, vector로 바꿔서 점수 순으로 내림차순 정렬
	내림차순 정렬된 벡터를 가지고 새로운 순위 벡터를 채운 후 이걸 순회하면서 출력하기
*/

map<int, int> c1;
map<int, int> c2;
map<int, int> c3;
map<int, int> sum;

int arr[4][100001];

bool compare(pair<int, int> a, pair<int, int> b) {
	if (a.second < b.second) return false;
	return true;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int N;
	cin >> N;
	for (int i = 0; i < 3; i++) {
		int count = 0;
		while (count < N) {
			int num;
			cin >> num;
			// cout << num << ' ';

			if (i == 0) {
				c1[count] = num;
			}
			else if (i == 1) {
				c2[count] = num;
			}
			else {
				c3[count] = num;
			}
			sum[count] += num;
			count++;
		}		
	}

	vector<pair<int, int>> vec1(c1.begin(), c1.end());
	vector<pair<int, int>> vec2(c2.begin(), c2.end());
	vector<pair<int, int>> vec3(c3.begin(), c3.end());
	vector<pair<int, int>> vec4(sum.begin(), sum.end());

	sort(vec1.begin(), vec1.end(), compare);
	sort(vec2.begin(), vec2.end(), compare);
	sort(vec3.begin(), vec3.end(), compare);
	sort(vec4.begin(), vec4.end(), compare);

	// for (auto p : vec1) {
	// 	cout << p.first << ' ' << p.second << '\n';
	// }

	arr[0][vec1[0].first] = 0;
	arr[1][vec2[0].first] = 0;
	arr[2][vec3[0].first] = 0;
	arr[3][vec4[0].first] = 0;

	for (int i = 1; i < vec1.size(); i++) {
		if (vec1[i].second == vec1[i - 1].second) {
			arr[0][vec1[i].first] = arr[0][vec1[i - 1].first];
		}
		else {
			arr[0][vec1[i].first] = i;
		}

		if (vec2[i].second == vec2[i - 1].second) {
			arr[1][vec2[i].first] = arr[1][vec2[i - 1].first];
		}
		else {
			arr[1][vec2[i].first] = i;
		}

		if (vec3[i].second == vec3[i - 1].second) {
			arr[2][vec3[i].first] = arr[2][vec3[i - 1].first];
		}
		else {
			arr[2][vec3[i].first] = i;
		}

		if (vec4[i].second == vec4[i - 1].second) {
			arr[3][vec4[i].first] = arr[3][vec4[i - 1].first];
		}
		else {	
			arr[3][vec4[i].first] = i;
		}
	}

	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < N; j++) {
			cout << arr[i][j] + 1 << ' ';
		}
		cout << '\n';
	}
}
