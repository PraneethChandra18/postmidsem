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

int dx[] = { 1,-1,0,0 };
int dy[] = { 0,0,1,-1 };

v32 graph[1000001], MARK(1000001, 0);
void dfs(int u, int clr) {
	for (auto x : graph[u]) {
		if (MARK[x] == 0) {
			MARK[x] = clr;
			dfs(x, clr);
		}
	}
}
int main()
{
	fastio;
	int n, m; cin >> n >> m;
	map <pair<lli, lli>, lli> pnts;
	map <pair<lli, lli>, lli> mark;
	int k; cin >> k;
	f(i, 0, k) {
		lli x, y; cin >> x >> y;
		x--, y--;
		if (pnts.find({ x,y }) == pnts.end())
			pnts.ist({ {x,y},i });
		mark.ist({ {x,y},0 });
	}
	map <pair<lli, lli>, lli>::iterator itr = pnts.begin();
	while (itr != pnts.end()) {
		lli x = itr->first.first, y = itr->first.second;
		lli z = itr->second;
		f(i, 0, 4) {
			lli nx, ny;
			nx = x + dx[i], ny = y + dy[i];
			if (pnts.find({ nx,ny }) != pnts.end() && mark[{nx, ny}] == 0) {
				graph[pnts[{nx, ny}]].pb(pnts[{x, y}]);
				graph[pnts[{x, y}]].pb(pnts[{nx, ny}]);
			}
		}
		mark[{x, y}] = 1;
		itr++;
	}
	int counter = 1;
	f(i, 0, k) {
		if (MARK[i] == 0) {
			MARK[i] = counter;
			dfs(i, counter);
			counter++;
		}
	}
	int ans[k] = { 0 };
	f(i, 0, k)ans[MARK[i]]++;
	int ANS = *max_element(ans, ans + k);
	cout << ANS << "\n";
	return 0;
}