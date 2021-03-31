#include<bits/stdc++.h>

using namespace std;
int inorder[100001];
int preorder[100001];
int find_pos[100001];
int n;

void func(int st1, int ed1, int st2, int ed2)
{
	if (st1 > ed1 || st2 > ed2) return;
	int root = preorder[ed2];
	cout << root << " ";
	int pos = find_pos[root];
	int num = pos - st1;
	func(st1, pos - 1, st2, st2 + num - 1);
	func(pos + 1, ed1, st2 + num, ed2 - 1);
}


int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> inorder[i];
	for (int i = 1; i <= n; i++) cin >> preorder[i];
	for (int i = 1; i <= n; i++) find_pos[inorder[i]] = i;
	func(1, n, 1, n);
	return 0;
}