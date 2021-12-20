#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>
#include <queue>

using namespace std;

vector<int> b(1001); // 건물 건설에 걸리는 시간 배열
vector<vector<int>> adj(1001); // 건물간 규칙 순서 배열
vector<int> cache(1001, -1); // memoization

int solve(int start){
	int len = adj[start].size();
	if(len == 0) return b[start];
	int maxs = -1;
	if(cache[start] != - 1) return cache[start];
	for(int i=0; i<adj[start].size(); i++){
		int end = adj[start][i];
		maxs = max(maxs, b[start] + solve(end));
	}
	return (cache[start]=maxs);
}

int main(){
	int t;
	scanf("%d", &t);
	while(t--){
		int N, K, start;
		scanf("%d %d", &N, &K);
		for(int i=1; i<=N; i++){
			scanf("%d", &b[i]);
		}
		for(int i=0; i<K; i++){
			int s, e;
			scanf("%d %d", &s, &e);
			adj[e].push_back(s); // 간선의 방향을 바꿈
		}
		scanf("%d", &start);
		
		int mins = solve(start);
		printf("%d \n", mins);
		/* vector 변수 초기화 */
		adj = vector<vector<int>>(1001);
		b = vector<int>(1001);
		cache = vector<int>(1001, -1);
	}
}