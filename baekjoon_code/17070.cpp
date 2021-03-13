#include<bits/stdc++.h>

using namespace std;

int N;
int lo[16][16];
int an = 0;

bool is_valid(int x, int y)
{
    if (x < 0 || y < 0 || x >= N || y >= N) return false;
    if (lo[x][y]) return false;
    return true;
}


void func(pair<int, int> st, pair<int, int> ed, int cnt)
{
    if (ed.first == N - 1 && ed.second == N - 1)
    {
        an++;
        return;
    }
    if (st.first == ed.first && st.second == ed.second - 1)
    {
        if (is_valid(ed.first, ed.second + 1))
        {
            pair<int, int> my = make_pair(ed.first, ed.second + 1);
            func(ed, my, cnt + 1);
        }
        if (is_valid(ed.first, ed.second + 1) && is_valid(ed.first + 1, ed.second + 1) && is_valid(ed.first + 1, ed.second))
        {
            pair<int, int> my = make_pair(ed.first + 1, ed.second + 1);
            func(ed, my, cnt + 1);
        }
    }
    else if (st.first == ed.first - 1 && st.second == ed.second)
    {
        if (is_valid(ed.first + 1, ed.second))
        {
            pair<int, int> my = make_pair(ed.first + 1, ed.second);
            func(ed, my, cnt + 1);
        }
        if (is_valid(ed.first, ed.second + 1) && is_valid(ed.first + 1, ed.second + 1) && is_valid(ed.first + 1, ed.second))
        {
            pair<int, int> my = make_pair(ed.first + 1, ed.second + 1);
            func(ed, my, cnt + 1);
        }
    }
    else if (st.first == ed.first - 1 && st.second == ed.second - 1)
    {
        if (is_valid(ed.first, ed.second + 1))
        {
            pair<int, int> my = make_pair(ed.first, ed.second + 1);
            func(ed, my, cnt + 1);
        }
        if (is_valid(ed.first + 1, ed.second))
        {
            pair<int, int> my = make_pair(ed.first + 1, ed.second);
            func(ed, my, cnt + 1);
        }
        if (is_valid(ed.first, ed.second + 1) && is_valid(ed.first + 1, ed.second + 1) && is_valid(ed.first + 1, ed.second))
        {
            pair<int, int> my = make_pair(ed.first + 1, ed.second + 1);
            func(ed, my, cnt + 1);
        }
    }
}



int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    pair<int, int> a, b;
    cin >> N;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++) cin >> lo[i][j];
    a.first = 0;
    a.second = 0;
    b.first = 0;
    b.second = 1;
    func(a, b, 0);
    cout << an;
    return 0;
}