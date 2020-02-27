#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>
#define R 1
#define G 2
#define B 3
using namespace std;
vector<vector<int>> ary;
vector<vector<bool>> visited;
int N, counts = 0;

void dfs(int here1, int here2) {
	int color = ary[here1][here2];
	
	if (here1 + 1 < N)
		if (color == ary[here1 + 1][here2] && !visited[here1 + 1][here2]) {
			visited[here1 + 1][here2] = true;
			dfs(here1 + 1, here2);
		}
	if (here1 - 1 >= 0)
		if (color == ary[here1 - 1][here2] && !visited[here1 - 1][here2]) {
			visited[here1 - 1][here2] = true;
			dfs(here1 - 1, here2);
		}
	if (here2 + 1 < N)
		if (color == ary[here1][here2 + 1] && !visited[here1][here2 + 1]) {
			visited[here1][here2 + 1] = true;
			dfs(here1, here2 + 1);
		}
	if (here2 - 1 >= 0)
		if (color == ary[here1][here2 - 1] && !visited[here1][here2 - 1]) {
			visited[here1][here2 - 1] = true;
			dfs(here1, here2 - 1);
		}
}
//모든 정점 방문
void dfsAll() {
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			if (!visited[i][j]) {
				visited[i][j] = true;
				dfs(i, j);
				counts++;
			}
}


int main() {
	cin >> N;
	ary = vector<vector<int>>(N, vector<int>(N));
	visited = vector<vector<bool>>(N, vector<bool>(N, false));
	for (int i = 0; i < N; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < N; j++) {
			if (s[j] == 'R') 
				ary[i][j] = R;
			
			else if (s[j] == 'G') 
				ary[i][j] = G;
			
			else 
				ary[i][j] = B;
		}
	}

	dfsAll();
	printf("%d ", counts);
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++) {
			if (ary[i][j] == R || ary[i][j] == G)
				ary[i][j] = R;

			else
				ary[i][j] = B;
		}

	visited = vector<vector<bool>>(N, vector<bool>(N, false));

	counts = 0;
	dfsAll();
	printf("%d \n", counts);
}

/*
5
RRRBB
GGBBB
BBBRR
BBRRR
RRRRR
*/
