#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>
#include <queue>

using namespace std;

int N, M, k;
int m[10001];
int parent[10001];

int find(int x){
	if(x == parent[x]) return x;
	return parent[x] = find(parent[x]);
}

void merge(int x, int y){
	x = find(x);
	y = find(y);
	if(x == y) return;
	if(m[x] > m[y]) parent[x] = y;
	else parent[y] = x;
}

int main(){
	cin>>N>>M>>k;
	
	for(int i=1; i<=N; i++)
		parent[i] = i;
	
	for(int i=1; i<=N; i++){
		cin>>m[i];
	}
	
	for(int i=0; i<M; i++){
		int u, v;
		cin>>u>>v;
		merge(find(u), find(v));
	}
	
	int sum = 0;
	for(int i=1; i<=N; i++){
		if(find(i) != 0){
			sum += m[find(i)];
			merge(0, find(i));
		}
	}
	
	if(k < sum) printf("Oh no \n");
	else printf("%d \n", sum);
}

/*
5 3 20
10 10 20 20 30
1 3
2 4
5 4

5 3 10
10 10 20 20 30
1 3
2 4
5 4

5 3 20
20 10 10 10 30
1 3 
2 4
5 4

5 2 50
10 10 10 10 20
1 2
3 4
*/