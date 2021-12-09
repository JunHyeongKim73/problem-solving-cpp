#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
using namespace std;

int arr[2][10001];
int cache[4][10001];

int N, W;
const int FULL = 3;
const int MIN_VAL = 99999; 

bool check(int i, int state){
	int n = (i + 1) & state;
	if(n == 0) return false;
	else return true;
}

int Solve(int status, int idx){
	int state = FULL - status; // 위 or 아래 배열에서 경우의 수를 따질 것인지
	// 기저조건
	if(start == N){
		// 마지막 index에서 몇 개의 그룹을 만들 수 있는지 구하여 반환한다.
		int count = 2;
		
		for(int i=0; i<2; i++){
			if(state & (i+1) == 0) 
				count--;
		}	
		// 만약 위 아래 성곽 모두 비어있다면
		if(count == 2){
			int u = arr[0][idx], d = arr[1][idx];
			if(u + d <= W)
				count = 1;
		}
			
		return count;
	}
	
	int& ret = cache[status][idx];
	if(ret != MIN_VAL) return ret;
	
	int u = arr[0][idx], nu = arr[0][idx+1];
	int d = arr[1][idx], nd = arr[1][idx+1];
	
	// 최대 경우의 수
	ret = 2 + Solve(0, idx + 1);
	// 경우를 나누어서 생각
	for(int cases=0; cases<4; cases++){
		// 위 아래 성곽 모두 비어있다면
		if(cases == 0){ 
			int num = 2;

			for(int i=0; i<2; i++){
				if(state & (i+1) == 0) 
					num--;
			}	
			// 만약 위 아래 성곽 모두 비어있다면
			if(num == 2){
				if(u + d <= W)
					num = 1;
			}
		}
		// cases에 맞지않는 state 값이면 건너뛴다
		if(state & cases == 0) continue;
		// 아래 성곽만 채워져있다면
		else if(cases == 1){
			if(u + nu > W) continue;
			num = 1;
		}
		// 위 성곽만 채워져있다면
		else if(cases == 2){
			if(d + nd > W) continue;
			num = 1;
		}
		// 위 아래 성곽 모두 채워져있다면
		else{
			if(u + nu > W || d + nd > W) continue;
			num = 2;
		}
		
		ret = min(ret, num + Solve(cases, idx + 1));
	}
	
	return ret;
}

int main(){
	int t;
	scanf("%d",&t);
	
	while(t--){
		scanf("%d%d",&N,&W);
		for(int i=0; i<2; i++)
			for(int j=1; j<=N; j++)
				scanf("%d",&arr[i][j]);
		
		for(int i=0; i<2; i++)
			memset(visited[i], -1, sizeof(visited[i]));
		
		memset(cache, MIN_VAL, sizeof(cache));
		
		int ans = Solve(0, 1);
		
	}
}
/*
1
8 100
70 60 55 43 57 60 44 50
58 40 47 90 45 52 80 40
*/