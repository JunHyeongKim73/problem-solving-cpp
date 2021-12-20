#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>
#include <queue>

using namespace std;

int N, M;

vector<pair<int, int>> adj[1001];
vector<bool> visited(1001, false);

struct Edge{
	int start, end, cost;
	
	Edge() : start(0), end(0), cost(0) {}
	Edge(int start, int end, int cost) : start(start), end(end), cost(cost) {}
	bool operator < (const Edge &edge) const{
		return cost > edge.cost;
	}
};

int main(){
	cin>>N;
	cin>>M;
	for(int i=0; i<M; i++){
		int a, b, c;
		cin>>a>>b>>c;
		adj[a].push_back(make_pair(b, c));
		adj[b].push_back(make_pair(a, c));
	}
	
	visited[1] = true;
	priority_queue<Edge> pq;
	for(int i=0; i<adj[1].size(); i++){
		pq.push(Edge(1, adj[1][i].first, adj[1][i].second));
	}
	int ans = 0;
	
	while(!pq.empty()){
		Edge e = pq.top();
		pq.pop();
		int start = e.end, cost = e.cost;
		if(visited[start]) continue;
		ans += cost;
		visited[start] = true;
		for(int i=0; i<adj[start].size(); i++){
			int ends = adj[start][i].first, costs = adj[start][i].second;
			pq.push(Edge(start, ends, costs));
		}
	}
	
	printf("%d \n", ans);
}

/*
6
9
1 2 5
1 3 4
2 3 2
2 4 7
3 4 6
3 5 11
4 5 3
4 6 8
5 6 8
*/