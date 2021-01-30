#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>
#include <queue>
#include <cstring>

using namespace std;

int N;
int maze[1001];
int cache[1001];

void solve(int idx, int n){
	if(idx == N - 1) return;
	for(int i=idx+1; i<=idx + maze[idx]; i++){
		if(i >= N) continue;
		if(n + 1 < cache[i] || cache[i] == -1){
			cache[i] = n + 1;
			solve(i, n + 1);
		}
	}
}

int main(){
	cin>>N;
	for(int i=0; i<N; i++) cin>>maze[i];
	memset(cache, -1, sizeof(cache));
	
	cache[0] = 0;
	solve(0, 0);
	
	printf("%d \n", cache[N - 1]);
}

/*
10
1 2 0 1 3 2 1 5 4 2

10
1 1 1 1 1 1 1 1 1 1

10
0 0 0 0 0 0 0 0 0 0
*/