#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1, -1, 0, 0 };
int R, C;
char ary[1001][1001];

//bfs
void bfs(int jx, int jy) {
	bool discovered[1001][1001];
	queue<int> t;
	queue<int> qc;
	queue<pair<int, int>> q;
	discovered[jx][jy] = true;
	for (int i = 0; i < R; i++)
		for (int j = 0; j < C; j++)
			if (ary[i][j] == 'F') {
				q.push({ i, j });
				qc.push(1);
				t.push(1);
			}
	q.push({ jx, jy }); qc.push(0); t.push(1);
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		int c = qc.front();
		int time = t.front();
		q.pop(); qc.pop(); t.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (c == 0) {
				if (ary[nx][ny] == 'F' || ary[nx][ny] == '#')
					continue;
				if (discovered[nx][ny] == true)
					continue;
				if (nx == R || nx == -1 || ny == C || ny == -1) {
					printf("%d ", time);
					return;
				}
				discovered[nx][ny] = true;
				ary[x][y] = '.';
				ary[nx][ny] = 'J';
				q.push({ nx, ny }); qc.push(0); t.push(time + 1);
			}
			else {
				if (ary[nx][ny] == 'F' || ary[nx][ny] == '#' || ary[nx][ny] == 'J')
					continue;
				if (nx == R || nx == -1 || ny == C || ny == -1)
					continue;
				ary[nx][ny] = 'F';
				q.push({ nx, ny }); qc.push(1); t.push(time + 1);
			}
		}
	}
	printf("IMPOSSIBLE\n");
}

int main() {
	cin >> R >> C;
	int jx, jy;
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			char c;
			cin >> c;
			if (c == 'J') {
				jx = i;
				jy = j;
			}
			ary[i][j] = c;
		}
	}
	
	bfs(jx, jy);
}

/*
4 4
J###
#..#
#..#
####

5 4
####
#.J#
#.##
#..F
####
*/
