#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>

using namespace std;

int N, M;
vector<vector<int>> ary;
vector<vector<bool>> visited;

void bfs() {
	queue<pair<int, int>> q;
	queue<bool> check;
	q.push(make_pair(0, 0));
	check.push(false);
	ary[0][0] = 2;
	visited[0][0] = true;

	while (!q.empty()) {
		int here1 = q.front().first;
		int here2 = q.front().second;

		int cost = ary[here1][here2];
		bool flag = check.front();

		q.pop();
		check.pop();

		if (here1 == N - 1 && here2 == M - 1) {
			printf("%d \n", cost - 1);
			return;
		}

		if (here1 + 1 < N) {
			if (ary[here1 + 1][here2] == 0 && flag) {
				q.push(make_pair(here1 + 1, here2));
				ary[here1 + 1][here2] = cost + 1;
				check.push(true);
			}
			else if (!visited[here1 + 1][here2] && !flag) {
				q.push(make_pair(here1 + 1, here2));
				visited[here1 + 1][here2] = true;
				ary[here1 + 1][here2] = cost + 1;
				check.push(false);
			}
			else if (ary[here1 + 1][here2] == 1 && !flag) {
				q.push(make_pair(here1 + 1, here2));
				check.push(true);
				ary[here1 + 1][here2] = cost + 1;
			}
		}
		if (here1 - 1 >= 0) {
			if (ary[here1 - 1][here2] == 0 && flag) {
				q.push(make_pair(here1 - 1, here2));
				ary[here1 - 1][here2] = cost + 1;
				check.push(true);
			}
			else if (!visited[here1 - 1][here2] && !flag) {
				q.push(make_pair(here1 - 1, here2));
				visited[here1 - 1][here2] = true;
				ary[here1 - 1][here2] = cost + 1;
				check.push(false);
			}
			else if (ary[here1 - 1][here2] == 1 && !flag) {
				q.push(make_pair(here1 - 1, here2));
				check.push(true);
				ary[here1 - 1][here2] = cost + 1;
			}
		}
		if (here2 + 1 < M) {
			if (ary[here1][here2 + 1] == 0 && flag) {
				q.push(make_pair(here1, here2 + 1));
				ary[here1][here2 + 1] = cost + 1;
				check.push(true);
			}
			else if (!visited[here1][here2+1] && !flag) {
				q.push(make_pair(here1, here2 + 1));
				visited[here1][here2 + 1] = true;
				ary[here1][here2 + 1] = cost + 1;
				check.push(false);
			}
			else if (ary[here1][here2 + 1] == 1 && !flag) {
				q.push(make_pair(here1, here2 + 1));
				check.push(true);
				ary[here1][here2 + 1] = cost + 1;
			}
		}
		if (here2 - 1 >= 0) {
			if (ary[here1][here2 - 1] == 0 && flag) {
				q.push(make_pair(here1, here2 - 1));
				ary[here1][here2 - 1] = cost + 1;
				check.push(true);
			}
			else if (!visited[here1][here2 - 1] && !flag) {
				q.push(make_pair(here1, here2 - 1));
				visited[here1][here2 - 1] = true;
				ary[here1][here2 - 1] = cost + 1;
				check.push(false);
			}
			else if (ary[here1][here2 - 1] == 1 && !flag) {
				q.push(make_pair(here1, here2 - 1));
				check.push(true);
				ary[here1][here2 - 1] = cost + 1;
			}
		}
	}
	printf("%d \n", -1);
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
			if (ary[i][j] == 1)
				visited[i][j] = true;
	

	bfs();
}
/*
4 6
010000
010001
010100
000100

6 4
0100
1110
1000
0000
0111
0000

3 6
010000
010111
000110
*/
