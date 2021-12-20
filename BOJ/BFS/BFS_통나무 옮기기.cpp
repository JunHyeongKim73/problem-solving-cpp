#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>
using namespace std;
int N;
char board[50][50];
int dist[50][50][2];
//동서남북
int dr[4] = { 0,0,1,-1 }, dc[4] = { 1,-1,0,0 };

struct s {
	int x, y, z;
};

void bfs() {
	//start row, start column, start state, end row, end column, end state
	int sr, sc, ss, er, ec, es;
	bool bflag = false, eflag = false;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (board[i][j] == 'B' && board[i + 1][j] == 'B' && !bflag) {
				sr = i + 1; sc = j; ss = 1; // 세로
				bflag = true;
			}
			else if(board[i][j] == 'B' && board[i][j + 1] == 'B' && !bflag){
				sr = i; sc = j + 1; ss = 0; // 가로
				bflag = true;
			}
			if (board[i][j] == 'E' && board[i + 1][j] == 'E' && !eflag) {
				er = i + 1; ec = j; es = 1; // 세로
				eflag = true;
			}
			else if (board[i][j] == 'E' && board[i][j + 1] == 'E' && !eflag) {
				er = i; ec = j + 1; es = 0; // 가로
				eflag = true;
			}
		}
	}
	queue<s> q;
	q.push({ sr,sc,ss });
	while (!q.empty()) {
		int r = q.front().x, c = q.front().y, s = q.front().z;
		q.pop();
		if (r == er && c == ec && s == es) {
			printf("%d \n", dist[r][c][s]);
			return;
		}
		//가로
		if (s == 0) {
			for (int i = 0; i < 4; i++) {
				int nr = r + dr[i], nc = c + dc[i], ns = s;
				if (i == 0 || i == 1) {
					nr += dr[i], nc += dc[i];
				}
				if (nr < 0 || nr >= N || nc < 0 || nc >= N) continue;
				char next = board[nr][nc];
				if (next == '1') continue;
				if (i == 0 || i == 1) {
					nr -= dr[i], nc -= dc[i];
				}
				//같은 상태로 방문한적 있는지 확인
				if (dist[nr][nc][ns]) continue;
				//남북으로 움직일때 검사
				if ((i == 2 || i == 3) && (board[nr][nc + 1] == '1' || board[nr][nc - 1] == '1')) continue;
				q.push({ nr,nc,ns });
				dist[nr][nc][ns] = dist[r][c][s] + 1;
			}
			//회전
			if (r == 0 || r == N - 1) continue;
			int sc = 1;
			if (dist[r][c][sc]) continue;
			char c1 = board[r - 1][c], c2 = board[r - 1][c - 1], c3 = board[r - 1][c + 1],
				c4 = board[r + 1][c], c5 = board[r + 1][c - 1], c6 = board[r + 1][c + 1];
			if (c1 == '1' || c2 == '1' || c3 == '1' || c4 == '1' || c5 == '1' || c6 == '1') continue;
			q.push({ r,c,sc });
			dist[r][c][sc] = dist[r][c][s] + 1;
		}
		//세로
		else {
			for (int i = 0; i < 4; i++) {
				int nr = r + dr[i], nc = c + dc[i], ns = s;
				if (i == 2 || i == 3) {
					nr += dr[i], nc += dc[i];
				}
				if (nr < 0 || nr >= N || nc < 0 || nc >= N) continue;
				char next = board[nr][nc];
				if (next == '1') continue;
				if (i == 2 || i == 3) {
					nr -= dr[i], nc -= dc[i];
				}
				//같은 상태로 방문한적 있는지 확인
				if (dist[nr][nc][ns]) continue;
				//동서로 움직일때 검사
				if ((i == 0 || i == 1) && (board[nr + 1][nc] == '1' || board[nr - 1][nc] == '1')) continue;
				q.push({ nr,nc,ns });
				dist[nr][nc][ns] = dist[r][c][s] + 1;
			}
			//회전
			if (c == 0 || c == N - 1) continue;
			int sc = 0;
			if (dist[r][c][sc]) continue;
			char c1 = board[r][c - 1], c2 = board[r - 1][c - 1], c3 = board[r + 1][c - 1], 
				c4 = board[r][c + 1], c5 = board[r + 1][c + 1], c6 = board[r - 1][c + 1];
			if (c1 == '1' || c2 == '1' || c3 == '1' || c4 == '1' || c5 == '1' || c6 == '1') continue;
			q.push({ r,c,sc });
			dist[r][c][sc] = dist[r][c][s] + 1;
		}
	}
	printf("%d \n", 0);
}

int main() {
	cin >> N;
	int r, c;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cin >> board[i][j];
	
	bfs();
}
/*
5
B0011
B0000
B0000
11000
EEE00

5
BBB00
10000
E0000
E0000
E0000
*/
