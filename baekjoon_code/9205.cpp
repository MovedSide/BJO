#include<bits/stdc++.h>

using namespace std;


int dist(pair<int, int> x, pair<int, int> y)
{
	return abs(x.first - y.first) + abs(x.second - y.second);
}




int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		pair<int, int> st, ed;
		pair<int, int> con[100];
		vector<int> gr[100];
		vector<int> gst, ged;
		queue<int> qu;
		bool vis[100] = { false, };
		cin >> st.first >> st.second;
		for (int i = 0; i < n; i++) cin >> con[i].first >> con[i].second;
		cin >> ed.first >> ed.second;
		if (dist(st, ed) <= 1000) qu.push(100);
		for (int i = 0; i < n; i++)
		{
			if (dist(con[i], st) <= 1000)
			{
				qu.push(i);
				vis[i] = true;
			}
			for (int j = i + 1; j < n; j++)
			{
				if (dist(con[i], con[j]) <= 1000)
				{
					gr[i].push_back(j);
					gr[j].push_back(i);
				}
			}
			if (dist(con[i], ed) <= 1000)
			{
				gr[i].push_back(100);
			}
		}
		bool happy = false;;
		while (!qu.empty())
		{
			auto el = qu.front();
			qu.pop();
			if (el == 100)
			{
				happy = true;
				break;
			}
			for (int ci : gr[el])
			{
				if (ci == 100)
				{
					happy = true;
					break;
				}
				if (!vis[ci])
				{
					qu.push(ci);
					vis[ci] = true;
				}
			}
		}
		if (happy) cout << "happy" << endl;
		else cout << "sad" << endl;
	}
	return 0;
}
