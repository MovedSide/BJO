#include<bits/stdc++.h>

using namespace std;

vector<string> ds;
vector<string> bs;
vector<string> dbs;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int N, M;
	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		string inp;
		cin >> inp;
		ds.push_back(inp);
	}
	sort(ds.begin(), ds.end());
	while (M--)
	{
		string inp;
		cin >> inp;
		if (binary_search(ds.begin(), ds.end(), inp))
		{
			dbs.push_back(inp);
		}
	}
	sort(dbs.begin(), dbs.end());
	cout << dbs.size() << endl;
	for (string el : dbs)
	{
		cout << el << endl;
	}
	return 0;
}