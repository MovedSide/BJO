#include <bits/stdc++.h>


using namespace std;

int n;
int st[100001];
bool vis[100001];
bool vis2[100001];

vector<int> find_st;

void dfs(int a)
{
	if (vis[a]) return;
	if (vis2[a])
	{
		auto index = find(find_st.begin(), find_st.end(), a);
		if (index == find_st.end()) return;
		for (int i = index - find_st.begin(); i < find_st.size(); i++)
		{
			vis[find_st[i]] = true;
		}
		return;
	}
	vis2[a] = true;
	find_st.push_back(a);
	dfs(st[a]);
}


void sol()
{
	for (int i = 1; i <= n; i++)
	{
		find_st.clear();
		dfs(i);
	}
	int cnt = 0;
	for (int i = 1; i <= n; i++)
	{
		if (!vis[i]) cnt++;
	}
	cout << cnt << "\n";
	return;
}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int T;
	cin >> T;
	while (T--)
	{
		cin >> n;
		memset(vis, false, sizeof(vis));
		memset(vis2, false, sizeof(vis2));
		for (int i = 1; i <= n; i++)
		{
			cin >> st[i];
		}
		sol();
	}
	return 0;
}