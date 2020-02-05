#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n;
vector<pair<int, double>> adj[10001];

vector<double> dijstra(int src) {
	vector<double> dist(n, 4.0);
	dist[src] = 1.0;
	priority_queue<pair<double, int>> pq;
	pq.push(make_pair(1.0, src));
	while (!pq.empty()) {
		double cost = pq.top().first;
		int here = pq.top().second;
		pq.pop();
		if (dist[here] < cost) continue;
		for (int i = 0; i < adj[here].size(); i++) {
			int there = adj[here][i].first;
			double nextDist = cost * adj[here][i].second;
			if (dist[there] > nextDist) {
				dist[there] = nextDist;
				pq.push(make_pair(nextDist, there));
			}
		}
	}
	return dist;
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		int m;
		cin >> n >> m;
		for (int i = 0; i < m; i++) {
			int a, b;
			double c;
			cin >> a >> b >> c;
			adj[a].push_back(make_pair(b, c));
			adj[b].push_back(make_pair(a, c));
		}

		vector<double> dist = dijstra(0);
		printf("%.10lf \n", dist[n - 1]);
	}
}
/*
1
7 14
0 1 1.3
0 2 1.1
0 3 1.24
3 4 1.17
3 5 1.24
3 1 2
1 2 1.31
1 2 1.26
1 4 1.11
1 5 1.37
5 4 1.24
4 6 1.77
5 6 1.11
2 6 1.2
*/