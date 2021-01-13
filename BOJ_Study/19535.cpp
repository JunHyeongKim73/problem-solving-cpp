#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>
#include <queue>

using namespace std;

int N;
long long d = 0;
vector<vector<int>> adj;
vector<bool> visited;

long long com(int n){
	long long result = 1;
	for(int i=n; i>n-3; i--){
		result *= i;
	}
	return (result / 6);
}

void dfs(int here){
	visited[here] = true;
	int len = adj[here].size();
	for(int i=0; i<len; i++){
		int there = adj[here][i];
		int len_there = adj[there].size();
		if(len_there == 1) visited[there] = true;
		d += (long long)((len - 1) * (len_there - 1));
		if(!visited[there])
			dfs(there);
	}
}

int main(){
	cin>>N;
	adj = vector<vector<int>>(N + 1);
	visited = vector<bool>(N + 1, false);
	for(int i=0; i<N-1; i++){
		int u, v;
		cin>>u>>v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	
	dfs(1);
	long long g = 0;
	for(int i=1; i<=N; i++){
		int len = adj[i].size();
		if(len >= 3){
			g += com(len);
		}
	}
	d = d / 2;
	if(d > 3 * g) printf("D \n");
	else if(d < 3 * g) printf("G \n");
	else if(d == g * 3) printf("DUDUDUNGA \n");
}