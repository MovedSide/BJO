#include<bits/stdc++.h>

using namespace std;


bool S[21];

int main()
{
	int M;
	cin >> M;
	while (M--)
	{
		char ch[7];
		string inp;
		int el;
		scanf("%s", ch);
		inp = ch;
		if (!inp.compare("add"))
		{
			scanf("%d", &el);
			S[el] = true;
		}
		else if (!inp.compare("remove"))
		{
			scanf("%d", &el);
			S[el] = false;
		}
		else if (!inp.compare("check"))
		{
			scanf("%d", &el);
			printf("%d\n", S[el]);
		}
		else if (!inp.compare("toggle"))
		{
			scanf("%d", &el);
			S[el] = !S[el];
		}
		else if (!inp.compare("all"))
		{
			for (int i = 1; i <= 20; i++) S[i] = true;
		}
		else if (!inp.compare("empty"))
		{
			for (int i = 1; i <= 20; i++) S[i] = false;
		}
	}
	return 0;
}
