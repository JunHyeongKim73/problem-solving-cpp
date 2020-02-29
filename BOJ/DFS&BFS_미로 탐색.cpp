#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>

using namespace std;

int N, M;
vector<vector<int>> ary;
vector<vector<bool>> visited;

void bfs(int start1, int start2) {
	queue<pair<int, int>> q;
	q.push(make_pair(start1, start2));
	ary[start1][start2] = 0;
	visited[start1][start2] = true;
	
	while (!q.empty()) {
		int here1 = q.front().first;
		int here2 = q.front().second;
		
		int cost = ary[here1][here2];
		
		if (here1 == N - 1 && here2 == M - 1) {
			printf("%d \n", cost + 1);
			return;
		}

		q.pop();
		
		if (here1 + 1 < N) {
			if (!visited[here1 + 1][here2]) {
				q.push(make_pair(here1 + 1, here2));
				ary[here1 + 1][here2] = cost + 1;
				visited[here1 + 1][here2] = true;
			}
		}
		if (here1 - 1 >= 0) {
			if (!visited[here1 - 1][here2]) {
				q.push(make_pair(here1 - 1, here2));
				ary[here1 - 1][here2] = cost + 1;
				visited[here1 - 1][here2] = true;
			}
		}
		if (here2 + 1 < M) {
			if (!visited[here1][here2 + 1]) {
				q.push(make_pair(here1, here2 + 1));
				ary[here1][here2 + 1] = cost + 1;
				visited[here1][here2 + 1] = true;
			}
		}
		if (here2 - 1 >= 0) {
			if (!visited[here1][here2 - 1]) {
				q.push(make_pair(here1, here2 - 1));
				ary[here1][here2 - 1] = cost + 1;
				visited[here1][here2 - 1] = true;
			}
		}
	}
}

int main() {
	cin >> N >> M;
	ary = vector<vector<int>>(N, vector<int>(M));
	visited = vector<vector<bool>>(N, vector<bool>(M));
	for (int i = 0; i < N; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < M; j++)
			ary[i][j] = s[j] - '0';
	}

	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			if (ary[i][j] == 0)
				visited[i][j] = true;

	bfs(0, 0);
}
/*
4 6
101111
101110
101011
111011
*/
