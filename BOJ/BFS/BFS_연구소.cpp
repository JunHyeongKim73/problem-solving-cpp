#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>

using namespace std;

vector<vector<int>> ary;
vector<int> av;
int N, M;

int bfs(vector<pair<int,int>> pos, int counts, int num) {
	queue<pair<int, int>> q;
	
	for (int i = 0; i < num; i++) {
		q.push(make_pair(pos[i].first, pos[i].second));
	}
	counts -= 3;

	while (!q.empty()) {
		int here1 = q.front().first;
		int here2 = q.front().second;

		q.pop();

		if (here1 + 1 < N) {
			if (ary[here1 + 1][here2] == 0) {
				q.push(make_pair(here1 + 1, here2));
				ary[here1 + 1][here2] = 1;
				counts--;
			}
		}
		if (here1 - 1 >= 0) {
			if (ary[here1 - 1][here2] == 0) {
				q.push(make_pair(here1 - 1, here2));
				ary[here1 - 1][here2] = 1;
				counts--;
			}
		}
		if (here2 + 1 < M) {
			if (ary[here1][here2 + 1] == 0) {
				q.push(make_pair(here1, here2 + 1));
				ary[here1][here2 + 1] = 1;
				counts--;
			}
		}
		if (here2 - 1 >= 0) {
			if (ary[here1][here2 - 1] == 0) {
				q.push(make_pair(here1, here2 - 1));
				ary[here1][here2 - 1] = 1;
				counts--;
			}
		}
	}
	return counts;
}

vector<vector<pair<int, int>>> ans;
vector<pair<int, int>> pv;
void backtrack(int n) {
	if (n == 0) {
		ans.push_back(pv);
		return;
	}
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			if (ary[i][j] == 0) {
				int flag = false;
				for (int m = 0; m < (3 - n); m++) {
					if (pv[m].first > i) {
						flag = true;
						break;
					}
					if (pv[m].first == i && pv[m].second >= j) {
						flag = true;
						break;
					}
				}
				if (!flag) {
					pv.push_back(make_pair(i, j));
					backtrack(n - 1);
					pv.pop_back();
				}
			}
}

int main() {
	cin >> N >> M;
	vector<vector<int>> v = vector<vector<int>>(N, vector<int>(M));
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			cin >> v[i][j];
	
	int num = 0, virus = 0;
	vector<pair<int, int>> pos;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++) {
			if (v[i][j] == 0)
				num++;
			if (v[i][j] == 2) {
				virus++;
				pos.push_back(make_pair(i, j));
			}
		}

	ary = v;
	backtrack(3);
	int len = ans.size();

	int max_num = 0;
	for (int i = 0; i < len; i++) {
		ary = v;
		ary[ans[i][0].first][ans[i][0].second] = 1;
		ary[ans[i][1].first][ans[i][1].second] = 1;
		ary[ans[i][2].first][ans[i][2].second] = 1;
		
		max_num = max(max_num, bfs(pos, num, virus));
	}
	printf("%d \n", max_num);
}
/*
7 7
2 0 0 0 1 1 0
0 0 1 0 1 2 0
0 1 1 0 1 0 0
0 1 0 0 0 0 0
0 0 0 0 0 1 1
0 1 0 0 0 0 0
0 1 0 0 0 0 0

8 8
2 0 0 0 0 0 0 2
2 0 0 0 0 0 0 2
2 0 0 0 0 0 0 2
2 0 0 0 0 0 0 2
2 0 0 0 0 0 0 2
0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0
*/
