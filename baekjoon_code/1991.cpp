#include<bits/stdc++.h>

using namespace std;


int tree[26][2];
int N;


void func1(int index)
{
	if (index == -1) return;
	char a = 'A' + index;
	cout << a;
	func1(tree[index][0]);
	func1(tree[index][1]);
}
void func2(int index)
{
	if (index == -1) return;
	char a = 'A' + index;
	func2(tree[index][0]);
	cout << a;
	func2(tree[index][1]);
}
void func3(int index)
{
	if (index == -1) return;
	char a = 'A' + index;
	func3(tree[index][0]);
	func3(tree[index][1]);
	cout << a;
}
int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		char inp1, inp2, inp3;
		cin >> inp1 >> inp2 >> inp3;
		if (inp2 != '.')
		{
			tree[inp1 - 'A'][0] = inp2 - 'A';
		}
		else tree[inp1 - 'A'][0] = -1;
		if (inp3 != '.')
		{
			tree[inp1 - 'A'][1] = inp3 - 'A';
		}
		else tree[inp1 - 'A'][1] = -1;
	}
	func1(0);
	cout << "\n";
	func2(0);
	cout << "\n";
	func3(0);
	return 0;
}