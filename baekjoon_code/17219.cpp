#include<bits/stdc++.h>

using namespace std;


int main()
{
	map<string, string> mp;
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int N, M;
	cin >> N >> M;
	while (N--)
	{
		string inp1, inp2;
		cin >> inp1 >> inp2;
		mp.insert(make_pair(inp1, inp2));
	}
	while (M--)
	{
		string inp1;
		cin >> inp1;
		cout << mp[inp1] << "\n";
	}
	return 0;
}