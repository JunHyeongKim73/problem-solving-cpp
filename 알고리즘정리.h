#pragma once
#include <iostream>
#include <vector>
#include <queue>
#define MAX_V 1000
using namespace std;

/*///dfs///
//adjlist
vector<vector<int>> adj;
vector<bool> visited;
//dfs
void dfs(int here) {
	visited[here] = true;
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
*////dfs///
/*///bfs///
//adjlist
vector<vector<int>> adj;
//bfs
vector<int> bfs(int start) {
	vector<bool> discovered(adj.size(), false);
	queue<int> q;
	vector<int> order;
	discovered[start] = true;
	q.push(start);
	while (!q.empty()) {
		int here = q.front();
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
	return order;
}
*////bfs///
/*///dijkstra///
int V;
#define MAX_V 1000
#define INF 9999
vector<pair<int, int>> adj[MAX_V];
//다익스트라
vector<int> dijkstra(int src) {
	vector<int> dist(V, INF);
	dist[src] = 0;
	priority_queue<pair<int, int>> pq;
	pq.push(make_pair(0, src));
	while (!pq.empty()) {
		int cost = -pq.top().first;
		int here = pq.top().second;
		pq.pop();
		//만약 지금 꺼낸 것보다 더 짧은 경로를 알면 지금 꺼낸 거 무시
		if (dist[here] < cost) continue;
		for (int i = 0; i < adj[here].size(); i++) {
			int there = adj[here][i].first;
			int nextDist = cost + adj[here][i].second;
			if (dist[there] > nextDist) {
				dist[there] = nextDist;
				pq.push(make_pair(-nextDist, there));
			}

		}
	}
	return dist;
}
*////다익스트라///
/*///벨만포드///
int V;
#define MAX_V 1000
#define INF 9999
vector<pair<int, int>> adj[MAX_V];
vector<int> bellmanFord(int src) {
	vector<int> upper(V, INF);
	upper[src] = 0;
	bool updated;
	//V번 반복
	for (int iter = 0; iter < V; iter++) {
		for(int here=0;here<V;here++)
			for (int i = 0; i < adj[here].size(); i++) {
				int there = adj[here][i].first;
				int cost = adj[here][i].second;
				//release
				if (upper[there] > upper[here] + cost) {
					upper[there] = upper[here] + cost;
				}
			}
		//완화 모두 완료
		if (!updated) break;
	}
	//음수 사이클 존재
	if (updated) upper.clear();
	return upper;
}
*////벨만포드///
/*///플로이드///
int V;
int adj[MAX_V][MAX_V];
void floyd() {
	//자기 자신으로 가는 최소치는 0
	for (int i = 0; i < V; i++) adj[i][i] = 0;
	for (int k = 0; k < V; k++)
		for (int i = 0; i < V; i++)
			for (int j = 0; j < V; j++)
				adj[i][j] = min(adj[i][j], adj[i][k] + adj[k][j]);
}
*////플로이드///
