#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>

using namespace std;

vector<vector<int>> adj; // Adjacency List 
vector<int> incNode; // 각 node의 incoming edge의 수를 저장하는 배열
int N, M;

int main(){
	scanf("%d %d",&N,&M);
	adj = vector<vector<int>>(N + 1);
	incNode = vector<int>(N + 1, 0);
	queue<int> q;
	
	for(int i=0; i<M; i++){
		int s, e;
		scanf("%d %d", &s, &e);
		
		adj[s].push_back(e);
		incNode[e]++;
	}
	/* incoming edge의 수가 0인 node를 넣어 q를 초기화 */
	for(int i=1; i<=N; i++){
		if(incNode[i] != 0) continue;
		q.push(i);
	}
	
	while(!q.empty()){
		int node = q.front();
		q.pop();
		
		for(int i=0; i<adj[node].size(); i++){
			int there = adj[node][i];
			incNode[there] --;
			/* 큐에서 pop한 노드의 간선을 지운 후 
			   노드의 incoming edge가 0이면 큐에 push */
			if(incNode[there] != 0) continue;
			q.push(there);
		}
		printf("%d ", node);
	}
	printf("\n");
}