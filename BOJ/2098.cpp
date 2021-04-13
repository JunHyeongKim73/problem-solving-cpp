#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>
#include <queue>
#include <cstring>
#include <map>

#define MAX 2000000000 
using namespace std;

int N;
vector<vector<int>> adj(16);
int cache[16][1<<16];

bool bitCheck(int state, int i){ // state의 i번째 bit가 1이면 true, 0이면 false를 반환
	return (state & 1<<i) ? true : false;
}

int DFS(int start, int state){
	if(state == (1<<N)-1) return adj[start][0];
	if(cache[start][state] != MAX) return cache[start][state];
	
	for(int i=0; i<N; i++){
		if(bitCheck(state, i)) continue; // state의 i번째 bit가 1이면 continue
		if(adj[start][i] == 0) continue; // 도시 i에서 도시 j로 갈 수 없으면 continue
		
		int ret = DFS(i, state | 1<<i);
		if(ret == 0) continue;
		cache[start][state] = min(cache[start][state], ret + adj[start][i]);
	}
	return cache[start][state];
}

int main(){
	scanf("%d", &N);
	
	for(int i=0; i<N; i++)
		for(int j=0; j<N; j++){
			int weight;
			scanf("%d", &weight);
			adj[i].push_back(weight);
		}
	
	fill(&cache[0][0], &cache[N-1][1<<N], MAX);
	int first = 1;
	int mins = DFS(0, first);
	
	printf("%d \n", mins);
}