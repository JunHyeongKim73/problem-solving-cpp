#include <iostream>
#include <vector>
#include <algorithm>
#define INF 9999
using namespace std;

int main() {
	int V, E;
	cin >> V >> E;
	vector<int> v(V);
	vector<vector<int>> adj(V, vector<int>(V, INF));
	vector<vector<int>> dist(V, vector<int>(V, 0));
	for (int i = 0; i < V; i++) cin >> v[i];
	for (int i = 0; i < E; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		adj[a - 1][b - 1] = c;
		adj[b - 1][a - 1] = c;
	}

	for (int i = 0; i < V; i++) adj[i][i] = 0;
	for (int k = 0; k < V; k++)
		for (int i = 0; i < V; i++)
			for (int j = 0; j < V; j++) {
				int maxDist = max(v[k], max(dist[i][k], dist[k][j]));
				if (adj[i][j] > adj[i][k] + adj[k][j] + maxDist) {
					adj[i][j] = adj[i][k] - dist[i][k] + adj[k][j] - dist[k][j] + maxDist;
					dist[i][j] = maxDist;
				}
			}

	int T;
	cin >> T;
	while (T--) {
		int s, t;
		cin >> s >> t;
		printf("%d \n", adj[s - 1][t - 1]);
	}

}
/*
8 12
8 6 5 8 3 5 8 4
1 6 9
1 2 3
2 8 3
6 8 5
6 7 3
8 7 3
6 5 5 
4 5 7
3 4 4
3 5 2
2 3 6
7 5 1
2
1 5
6 3

*/