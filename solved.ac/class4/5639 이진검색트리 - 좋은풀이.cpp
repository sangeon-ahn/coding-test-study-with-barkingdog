#include<iostream>
#include<algorithm>
using namespace std;

int preorder[10005] = {};
void postorder(int s, int e)
{
	if (s  >= e)
		return;
	auto it = upper_bound(preorder + s, preorder + e, preorder[s]);
	int dist = distance(preorder, it);
	postorder(s + 1, dist);
	postorder(dist, e);
	cout << preorder[s] << "\n";
}

int main()
{
	cin.tie(0);
	ios::sync_with_stdio(0);
	int i = 0;
	while (cin >> preorder[i++]);
	
	postorder(0, i - 1);
	
}