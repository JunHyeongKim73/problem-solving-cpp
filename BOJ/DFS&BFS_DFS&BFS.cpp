#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

//adjlist
vector<vector<int>> adj;
vector<bool> visited;
//dfs
void dfs(int here) {
	visited[here] = true;
	printf("%d ", here);
	for (int i = 0; i < adj[here].size(); i++) {
		int there = adj[here][i];
		if (!visited[there])
			dfs(there);
	}
}
//모든 정점 방문
void dfsAll() {
	visited = vector<bool>(adj.size(), false);
	for (int i = 0; i < adj.size(); i++)
		if (!visited[i])
			dfs(i);
}

void bfs(int start) {
	vector<bool> discovered(adj.size(), false);
	queue<int> q;
	vector<int> order;
	discovered[start] = true;
	q.push(start);
	while (!q.empty()) {
		int here = q.front();
		printf("%d ", here);
		q.pop();
		order.push_back(here);
		for (int i = 0; i < adj[here].size(); i++) {
			int there = adj[here][i];
			if (!discovered[there]) {
				q.push(there);
				discovered[there] = true;
			}
		}
	}
}

int main() {
	int N, M, V;
	cin >> N >> M >> V;
	adj = vector<vector<int>>(N + 1);
	visited = vector<bool>(N + 1, false);
	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	for(int i=0;i<=N;i++)
		sort(adj[i].begin(), adj[i].end());

	dfs(V);
	printf("\n");
	bfs(V);
}
/*
4 5 1
2 4
2 3
2 1
1 3
1 4

4 5 1
1 2
1 3
1 4
2 4
3 4
*/
