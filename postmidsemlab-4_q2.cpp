#include<bits/stdc++.h>
using namespace std;
int flag = 0;
class graph
{
public:
	int N;
	list <int>* adj;
	int * color;
	int * visited;
	graph(int N);
	list<int>q;
	void add_edge(int x, int y);
	void is_bipartite();
	void BFS();
	void set(int v);

};

graph::graph(int N) {
	this->N = N;
	adj = new list<int>[N];
	color = new int[N];
	visited = new int[N];
	for (int i = 0; i < N; i++)
	{
		color[i] = -1;
		visited[i] = 0;
	}
}

void graph::add_edge(int x, int y)
{
	adj[x].push_back(y);
	adj[y].push_back(x);
}

void graph::is_bipartite()
{
	color[0] = 0;
	visited[0] = 1;
	q.push_back(0);
	BFS();
	for (int z = 0; z < N; z++)
	{
		if (!visited[z]) {
			color[z] = 0;
			visited[z] = 1;
			q.push_back(z);
		}
	}
}
void graph::BFS()
{
	int v = q.front();
	while (!q.empty())
	{
		q.pop_front();
		for (auto i : adj[v])
		{
			if (color[i] == -1) {
				q.push_back(i);
				color[i] = 1 - color[v];
				visited[i] = 1;
			}
			else if (color[i] == color[v])
				flag = 1;
		}
		BFS();
	}
}
void graph::set(int v)
{
	N = v;
}

int main()
{
	int n, m;
	cin >> n >> m;
	graph g(n + m);
	int edges = m;
	int max = n;
	while (edges--)
	{
		int x, y, weight;
		cin >> x >> y >> weight;
		if (weight % 2 == 0)
		{
			g.add_edge(x, max);
			g.add_edge(y, max);
			max++;
		}
		else
		{
			g.add_edge(x, y);
		}
	}
	g.set(max);
	g.is_bipartite();
	if (flag)
		cout << "YES";
	else
		cout << "NO";
}