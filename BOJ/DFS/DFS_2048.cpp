#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>
using namespace std;

int board[20][20], max_num = -1;
int N;

//동 서 남 북
void move(int dir) {
	if (dir == 0) {
		for (int i = 0; i < N; i++) {
			int val = -1;
			vector<int> v;
			for (int j = N - 1; j >= 0; j--) {
				if (board[i][j] == 0) continue;
				if (val == board[i][j]) {
					v.push_back(val * 2);
					val = -2;
				}
				else if (val > 0 && val != board[i][j]) {
					v.push_back(val); 
					val = board[i][j];
				}
				else if (board[i][j] != 0) val = board[i][j];
				board[i][j] = 0;
			}
			if (val > 0) v.push_back(val);
			for (int j = 0; j < v.size(); j++)
				board[i][N - 1 - j] = v[j];
			v.clear();
		}
	}
	else if (dir == 1) {
		for (int i = 0; i < N; i++) {
			int val = -1;
			vector<int> v;
			for (int j = 0; j < N; j++) {
				if (board[i][j] == 0) continue;
				if (val == board[i][j]) {
					v.push_back(val * 2);
					val = -2;
				}
				else if (val > 0 && val != board[i][j]) {
					v.push_back(val);
					val = board[i][j];
				}
				else if (board[i][j] != 0) val = board[i][j];
				board[i][j] = 0;
			}
			if (val > 0) v.push_back(val);
			for (int j = 0; j < v.size(); j++)
				board[i][j] = v[j];
			v.clear();
		}
	}
	else if (dir == 2) {
		for (int j = 0; j < N; j++) {
			int val = -1;
			vector<int> v;
			for (int i = N - 1; i >= 0; i--) {
				if (board[i][j] == 0) continue;
				if (val == board[i][j]) {
					v.push_back(val * 2);
					val = -2;
				}
				else if (val > 0 && val != board[i][j]) {
					v.push_back(val);
					val = board[i][j];
				}
				else if (board[i][j] != 0) val = board[i][j];
				board[i][j] = 0;
			}
			if(val > 0) v.push_back(val);
			for (int i = 0; i < v.size(); i++)
				board[N - 1 - i][j] = v[i];
			v.clear();
		}
	}
	else if (dir == 3) {
		for (int j = 0; j < N; j++) {
			int val = -1;
			vector<int> v;
			for (int i = 0; i < N; i++) {
				if (board[i][j] == 0) continue;
				if (val == board[i][j]) {
					v.push_back(val * 2);
					val = -2;
				}
				else if (val > 0 && val != board[i][j]) {
					v.push_back(val);
					val = board[i][j];
				}
				else if (board[i][j] != 0) val = board[i][j];
				board[i][j] = 0;
			}
			if(val > 0) v.push_back(val);
			for (int i = 0; i < v.size(); i++)
				board[i][j] = v[i];
			v.clear();
		}
	}
}

void DFS(int n) {
	if (n == 5) {
		for (int i = 0; i < N; i++)
			for (int j = 0; j < N; j++)
				max_num = max(max_num, board[i][j]);
		return;
	}
	int temp[20][20];
	for (int i = 0; i < N; i++) 
		for (int j = 0; j < N; j++) 
			temp[i][j] = board[i][j];

	for (int i = 0; i < 4; i++) {
		move(i);
		/*printf("\n\n");
		if (n == 0) printf("##############################\n");
		printf("%d %d\n", n + 1, i);
		for (int j = 0; j < N; j++) {
			for (int k = 0; k < N; k++)
				printf("%d ", board[j][k]);
			printf("\n");
		}*/
		DFS(n + 1);
		for (int j = 0; j < N; j++) for (int k = 0; k < N; k++) board[j][k] = temp[j][k];
	}
}

int main() {
	cin >> N;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cin >> board[i][j];
	DFS(0);
	printf("%d \n", max_num);
}
/*
3
2 2 2
4 4 4
8 8 8

3
256 8 128
16 0 256
0 8 0
*/
