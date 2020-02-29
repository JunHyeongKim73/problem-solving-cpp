#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>
using namespace std;
int N, M;
vector<vector<int>> ary;
vector<vector<int>> cp;
int dr[4] = { 0,0,1,-1 };
int dc[4] = { 1,-1,0,0 };

int bfs(int r, int c) {
	queue<pair<int, int>> q;
	q.push(make_pair(r, c));
	
	int max_cost = 0;

	while (!q.empty()) {
		int lr = q.front().first;
		int lc = q.front().second;
		q.pop();

		int cost = ary[lr][lc];
		max_cost = max(max_cost, cost);

		for (int i = 0; i < 4; i++) {
			if (i == 0 && lc == M - 1) //동
				continue;
			if (i == 1 && lc == 0) //서
				continue;
			if (i == 2 && lr == N - 1) //남
				continue;
			if (i == 3 && lr == 0) //북
				continue;
			if (ary[lr + dr[i]][lc + dc[i]] == 1) {
				ary[lr + dr[i]][lc + dc[i]] = cost + 1;
				q.push(make_pair(lr + dr[i], lc + dc[i]));
			}
		}
	}
	
	return max_cost - 2;
}

//모든 L에 대해서 bfs
//최대가 50x50이므로 시간초과x
int bfsAll() {
	int max_num = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (ary[i][j] == 1) {
				ary[i][j] = 2;
				max_num = max(max_num, bfs(i, j));
				ary = cp;
			}
		}
	}
	return max_num;
}

int main() {
	cin >> N >> M;
	ary = vector<vector<int>>(N, vector<int>(M));
	cp = vector<vector<int>>(N, vector<int>(M));
	for (int i = 0; i < N; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < M; j++) {
			if (s[j] == 'W')
				cp[i][j] = 0;
			else if (s[j] == 'L')
				cp[i][j] = 1;
		}
	}

	ary = cp;
	printf("%d \n", bfsAll());
}
/*
5 7
WLLWWWL
LLLLLLL
LWLWLWW
LWLWLLL
WLLWLWW

3 4
WLWL
WLWL
LWLL

LWLW
LWLW
LWWL

5 8
LLWLWWWW
LLLLLLWL
LWWLWWWL
LWLLLWWL
LLWLWWWW
*/
