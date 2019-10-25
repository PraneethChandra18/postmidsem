#include <bits/stdc++.h>
#define lli long long int
#define pb push_back
#define mod 1000000007
#pragma GCC optimize ("-O2")
#define mod2 998244353
#define MAXN 1000000000
#define v32 vector<int>
#define v64 vector<lli>
#define v1024 vector <vector <int>>
#define v4096 vector <vector <lli>>
#define vt vector
#define f(x, y, z) for (lli x = y; x < z; x++)
#define fd(x, y, z) for (lli x = y; x > z; x--)
#define lb lower_bound
#define ld long double
#define m64 map<lli,lli>
#define m32 map<int,int>
#define m64it map<lli,lli>::iterator
#define m32it map<int,int>::iterator
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define ist insert
#define endl "\n"
#include <ext/pb_ds/assoc_container.hpp>
#define p_q priority_queue 
#define min_p_q priority_queue <int,vt <int>,greater <int>>
using namespace std;
using namespace __gnu_pbds;
template <typename T>
void DEBUG_ARR(vt<T> a)
{
	f(i, 0, a.size())cout << a[i] << " ";
	cout << "\n";
}
int col[1000001];
bool is_it_visited[1000001];
vector<int> adj[1000001];
int k, m, n, c, maxi, cl, mc;
void dfs(int v)
{
	is_it_visited[v] = true;
	c++;
	for (auto p : adj[v])
		if (!is_it_visited[p])
			dfs(p);
}
int getnum(int x, int y)
{
	return n * x + y;
}

int main()
{
	cin >> n >> m >> c;
	vector<int> input;
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			int color;
			cin >> color;
			col[getnum(i, j)] = color;
			input.push_back(getnum(i, j));
		}
	}
	for (auto it : input)
	{
		int x = it / n, y = it % n;
		if (y + 1 < n && col[getnum(x, y + 1)] == col[getnum(x, y)])
		{
			adj[getnum(x, y + 1)].push_back(it);
			adj[it].push_back(getnum(x, y + 1));
		}
		if (x + 1 < m && col[getnum(x + 1, y)] == col[getnum(x, y)])
		{
			adj[getnum(x + 1, y)].push_back(it);
			adj[it].push_back(getnum(x + 1, y));
		}
	}
	for (auto it : input)
	{
		if (!is_it_visited[it])
		{
			c = 0;
			dfs(it);
			if (c > maxi)
			{
				maxi = c;
				mc = col[it];
			}
		}
	}
	cout << maxi << " " << mc;
	return 0;
}