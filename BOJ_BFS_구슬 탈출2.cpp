#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>
using namespace std;
int N, M;
char ary[10][10];
bool visited[10][10][10][10];

void bfs() {
	queue<pair<int, int>> red, blue;
	queue<int> dir;
	queue<int> c;
	//동서남북
	int dx[4] = { 0, 0, 1, -1 };
	int dy[4] = { 1, -1, 0, 0 };
	//R, B를 queue에 넣고 goal의 위치를 기억하며 시작
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++) {
			if (ary[i][j] == 'R')
				red.push(make_pair(i, j));
			if (ary[i][j] == 'B')
				blue.push(make_pair(i, j));
		}
	c.push(1);
	while (!red.empty()) {
		int rx = red.front().first;
		int ry = red.front().second;
		int bx = blue.front().first;
		int by = blue.front().second;
		red.pop(); blue.pop();


		int counts = c.front();
		c.pop();
		if (counts > 10) {
			printf("%d \n", -1);
			return;
		}

		//i:0 == 동 . i:1 == 서
		//i:2 == 남 . i:3 == 북
		for (int i = 0; i < 4; i++) {
			int nrx = rx + dx[i];
			int nry = ry + dy[i];
			int nbx = bx + dx[i];
			int nby = by + dy[i];

			//파란색 구슬 움직이기
			while (1) {
				if (ary[nbx][nby] == '#') {
					nbx -= dx[i]; nby -= dy[i];
					break;
				}
				if (ary[nbx][nby] == 'O')
					break;
				nbx += dx[i]; nby += dy[i];
			}

			//빨간색 구슬 움직이기
			while (1) {
				if (ary[nrx][nry] == '#') {
					nrx -= dx[i]; nry -= dy[i];
					break;
				}
				if (ary[nrx][nry] == 'O')
					break;
				nrx += dx[i]; nry += dy[i];
			}

			//파란색 구슬이 구멍에 빠졌다면 continue
			if (ary[nbx][nby] == 'O')
				continue;

			//빨간색 구슬이 구멍에 빠졌다면 return
			if (ary[nrx][nry] == 'O') {
				printf("%d \n", counts);
				return;
			}

			//두 구슬의 위치가 같다면 위치를 조정해준다
			if (nrx == nbx && nry == nby) {
				switch (i){
				
				case 0: //동
					ry > by ? nby -= 1 : nry -= 1;
					break;
				case 1: //서
					ry < by ? nby += 1 : nry += 1;
					break;
				case 2: //남
					rx > bx ? nbx -= 1 : nrx -= 1;
					break;
				case 3: //북
					rx < bx ? nbx += 1 : nrx += 1;
					break;
				}
			}
			//방문하지 않았다면 queue에 넣는다
			if (!visited[nrx][nry][nbx][nby]) {
				red.push(make_pair(nrx, nry));
				blue.push(make_pair(nbx, nby));
				c.push(counts + 1);
				visited[nrx][nry][nbx][nby] = true;
			}
		}
	}
	printf("%d \n", -1);
}

int main() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < M; j++) 
			ary[i][j] = s[j];
		
	}

	bfs();
}

/*
5 5
#####
#..B#
#.#.#
#RO.#
#####

7 7
#######
#...RB#
#.#####
#.....#
#####.#
#O....#
#######

6 7
#######
#..BR##
#.#####
#.#O###
#....##
#######

6 7
#######
#....##
#.#####
#.#O###
#..RB##
#######
*/
