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
class UnionFind //rank is equal to number of vertices in a connected component
{
public: v32 p, rank;
		// remember: vi is vector<int>
		UnionFind(int N) {
			rank.assign(N, 1);
			p.assign(N, 0); for (int i = 0; i < N; i++) p[i] = i;
		}
		int findSet(int i) { return (p[i] == i) ? i : (p[i] = findSet(p[i])); }
		bool isSameSet(int i, int j) { return findSet(i) == findSet(j); }
		void unionSet(int i, int j)
		{
			if (!isSameSet(i, j)) {
				// if from different set
				int x = findSet(i), y = findSet(j);
				if (rank[x] > rank[y]) p[y] = x, rank[x] += rank[y];
				// rank keeps the tree short
				else
				{
					p[x] = y;
					rank[y] += rank[x];
				}

			}

		}
};

vt <pair<lli, pair<int, int>>> EDGES;
int main()
{
	fastio;
	int n, m; cin >> n >> m;
	f(i, 0, m) {
		int x, y; cin >> x >> y;
		lli z; cin >> z;
		EDGES.pb({ z,{x,y} });
	}
	sort(EDGES.rbegin(), EDGES.rend());
	UnionFind DSU(n + 1);
	lli ans = 1;
	int count = 0;
	f(i, 0, m) {
		if (!DSU.isSameSet(EDGES[i].second.first, EDGES[i].second.second)) {
			ans = (ans*(EDGES[i].first) % mod) % mod;
			DSU.unionSet(EDGES[i].second.first, EDGES[i].second.second);
		}
	}
	cout << (ans%mod + mod) % mod << "\n";
	return 0;
}