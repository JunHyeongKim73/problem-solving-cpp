#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>
using namespace std;
int N, M;
vector<vector<int>> bf;
vector<vector<int>> af;
int dr[4] = { 0,0,1,-1 };
int dc[4] = { 1,-1,0,0 };

bool bfs(int r, int c, int counts) {
	vector<vector<bool>> visited(N, vector<bool>(M, true));
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			if (bf[i][j] > 0)
				visited[i][j] = false;

	queue<pair<int, int>> q;
	q.push(make_pair(r, c));
	visited[r][c] = true;

	int num = 0;
	while (!q.empty()) {
		int cr = q.front().first;
		int cc = q.front().second;
		q.pop();
		
		num++;
		for (int i = 0; i < 4; i++)
			if (!visited[cr + dr[i]][cc + dc[i]]) {
				visited[cr + dr[i]][cc + dc[i]] = true;
				q.push(make_pair(cr + dr[i], cc + dc[i]));
			}
	}

	visited.clear();
	if (num != counts)
		return true;
	else
		return false;
}

int main() {
	cin >> N >> M;
	bf = vector<vector<int>>(N, vector<int>(M));
	af = vector<vector<int>>(N, vector<int>(M, 0));
	int counts = 0;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++) {
			cin >> bf[i][j];
			af[i][j] = bf[i][j];
			if (bf[i][j] > 0)
				counts++;
		}
	
	int num = 0;

	while (1) {
		if (counts == 0) {
			printf("%d \n", 0);
			break;
		}

		bf = af;

		bool forflag = false;
		bool finish = false;
		for (int i = 0; i < N; i++)
			if (!forflag)
				for (int j = 0; j < M; j++)
					if (bf[i][j] > 0) {
						finish = bfs(i, j, counts);
						forflag = true;
						break;
					}

		if (finish) {
			printf("%d \n", num);
			break;
		}

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (bf[i][j] > 0) {
					af[i][j] = bf[i][j];
					for (int k = 0; k < 4; k++) {
						if (bf[i + dr[k]][j + dc[k]] == 0 && af[i][j] > 0)
							af[i][j]--;
					}
					if (af[i][j] == 0)
						counts--;
				}
			}
		}

		num++;
	}
	//bfs(counts);
}
/*
5 7
0 0 0 0 0 0 0
0 2 4 5 3 0 0
0 3 0 2 5 2 0
0 7 6 2 4 0 0
0 0 0 0 0 0 0

6 7
0 0 0 0 0 0 0
0 3 4 2 4 0 0
0 4 0 4 10 1 0
0 6 4 8 4 0 0
0 4 7 4 4 0 0
0 0 0 0 0 0 0
*/
