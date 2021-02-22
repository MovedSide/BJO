#include<bits/stdc++.h>

using namespace std;



map<string, int> mp;
string pk[100001];
int N, M;
char inp1[21];
int main()
{
	cin >> N >> M;
	for (int i = 1; i <= N; i++)
	{
		scanf("%s", inp1);
		mp.insert(make_pair(inp1, i));
		pk[i] = inp1;
	}
	while (M--)
	{
		scanf("%s", inp1);
		if (inp1[0] >= 'A' && inp1[0] <= 'Z')
		{
			string inp = inp1;
			printf("%d\n", mp[inp]);
		}
		else
		{
			int num = atoi(inp1);
			cout << pk[num] << "\n";
		}
	}
	return 0;
}