#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
#include <stack>
using namespace std;
const int MIN = 20000000;

int N, W;
int cases[1003][2];
int cache[1003][1003];

int Distance(pair<int, int> cPrev, pair<int, int> cNext){
	return abs(cNext.first - cPrev.first) + abs(cNext.second - cPrev.second);
}
/* 
 첫번째 경찰차가 맡은 사건: a 번째 사건
 두번째 경찰차가 맡은 사건: b 번째 사건
 i번째 사건을 처리해야한다
*/
int Solve(int a, int b, int i){
	int num;
	int& ret = cache[a][b];
	// 기저조건
	if(i == W+1){
		// 마지막 사건의 좌표
		int nx = cases[i][0], ny = cases[i][1];
		// 첫번째 경찰차의 좌표
		int fx = cases[a][0], fy = cases[a][1];
		// 첫번째 경찰차가 맡았을 때의 거리
		int fdist = Distance({fx,fy},{nx,ny});
		// 두번째 경찰차의 좌표
		int sx = cases[b][0], sy = cases[b][1];
		// 두번째 경찰차가 맡았을 때의 거리
		int sdist = Distance({sx,sy},{nx,ny});
		
		ret = min(fdist, sdist);
		
		return ret;
	}
	
	if(ret != MIN) return ret;
	// i번째 사건의 좌표
	int nx = cases[i][0], ny = cases[i][1];
	// 첫번째 경찰차
	int fx = cases[a][0], fy = cases[a][1];
	int fdist = Distance({fx, fy}, {nx, ny});
	// 두번째 경찰차
	int sx = cases[b][0], sy = cases[b][1];
	int sdist = Distance({sx, sy}, {nx, ny});
	
	// 첫번째 경찰차의 경우의 수
	ret = min(ret, fdist + Solve(i, b, i+1));
	// 두번째 경찰차의 경우의 수
	ret = min(ret, sdist + Solve(a, i, i+1));
	
	return ret;
}

void Reconstruct(int a, int b, int i){
	if(i == W+1){
		int nx = cases[i][0], ny = cases[i][1];
		int x, y, dist;
		// 첫번째 경찰차 좌표
		x = cases[a][0], y = cases[a][1];
		dist = Distance({x, y}, {nx, ny});
		// 두번째 경찰차의 좌표는 고려할 필요가 없다.
		if(dist == cache[a][b]) printf("%d \n", 1);
		else printf("%d \n", 2);
		
		return;
	}
	// i번째 사건의 좌표
	int nx = cases[i][0], ny = cases[i][1];
	int x, y, dist, cacheDist;
	// 첫번째 경찰차 좌표
	x = cases[a][0], y = cases[a][1];
	dist = Distance({x, y}, {nx, ny});
	// 첫번째 경찰차를 선택했을 때의 cache값 차이
	cacheDist = cache[a][b] - cache[i][b];
	
	if(dist[0] == cacheDist[0]){
		printf("%d \n", 1);
		Reconstruct(i, b, i+1);
	}
	else{
		printf("%d \n", 2);
		Reconstruct(a, i, i+1);
	}
}

int main(){
	scanf("%d", &N);
	scanf("%d", &W);
	for(int i=2; i<W+2; i++)
		scanf("%d %d", &cases[i][0], &cases[i][1]);
	// 경찰차의 초기 위치를 사건의 위치로 저장한다
	cases[0][0] = 1; cases[0][1] = 1;
	cases[1][0] = N; cases[1][1] = N;
	
	fill(&cache[0][0], &cache[1002][1003], MIN);
	// cases[2]부터 첫번째 사건이 저장되어있다
	int mins = Solve(0, 1, 2);
	
	printf("%d \n", mins);
	
	Reconstruct(0, 1, 2);
}