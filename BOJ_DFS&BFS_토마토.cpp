#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>

using namespace std;

int N, M;
vector<vector<int>> ary;

void bfs(int zero_num) {
	queue<pair<int, int>> q;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			if (ary[i][j] == 1) {
				q.push(make_pair(i, j));
			}

	int day = 0;

	while (!q.empty()) {
		int here1 = q.front().first;
		int here2 = q.front().second;

		q.pop();

		int cost = ary[here1][here2];
		if (cost != 1)
			zero_num--;

		if (zero_num == 0) {
			printf("%d \n", cost - 1);
			return;
		}

		if (here1 + 1 < N) {
			if (ary[here1 + 1][here2] == 0) {
				q.push(make_pair(here1 + 1, here2));
				ary[here1 + 1][here2] = cost + 1;
			}
		}
		if (here1 - 1 >= 0) {
			if (ary[here1 - 1][here2] == 0) {
				q.push(make_pair(here1 - 1, here2));
				ary[here1 - 1][here2] = cost + 1;
			}
		}
		if (here2 + 1 < M) {
			if (ary[here1][here2 + 1] == 0) {
				q.push(make_pair(here1, here2 + 1));
				ary[here1][here2 + 1] = cost + 1;
			}
		}
		if (here2 - 1 >= 0) {
			if (ary[here1][here2 - 1] == 0) {
				q.push(make_pair(here1, here2 - 1));
				ary[here1][here2 - 1] = cost + 1;
			}
		}
	}
	printf("%d \n", -1);
}

int main() {
	cin >> M >> N;
	ary = vector<vector<int>>(N, vector<int>(M));
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			cin >> ary[i][j];

	int zero_num = 0;
	int one_num = 0;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			if (ary[i][j] == 0)
				zero_num++;
		
	bfs(zero_num);
}
/*
6 4
1 2 2 3 4 4
2 2 1 2 3 3
3 3 2 3 3 2
4 4 3 3 2 1
*/
