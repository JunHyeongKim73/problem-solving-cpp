#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int N;
int S[20][20];
int minSum = 9999;
bool visited[20];
vector<int> link;

void solve(int n, vector<int> start) {
	if (n == N / 2) {
		for (int i = 0; i < N; i++)
			if (!visited[i])
				link.push_back(i);

		int dif;
		int startSum = 0, linkSum = 0;
		for (int i = 0; i < N / 2; i++)
			for (int j = 0; j < i; j++) {
				startSum += S[start[i]][start[j]];
				startSum += S[start[j]][start[i]];
			}
		for (int i = 0; i < N / 2; i++)
			for (int j = 0; j < i; j++) {
				linkSum += S[link[i]][link[j]];
				linkSum += S[link[j]][link[i]];
			}
		dif = abs(startSum - linkSum);
		if (minSum > dif)
			minSum = dif;
		link.clear();
		return;
	}
	for (int i = 0; i < N; i++) {
		if (!visited[i]) {
			if (n != 0)
				if (start[n - 1] >= i)
					continue;
			start.push_back(i);
			visited[i] = true;
			solve(n + 1, start);
			start.pop_back();
			visited[i] = false;
		}
	}
}

int main(void){
	cin >> N;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cin >> S[i][j];

	vector<int> start;
	solve(0, start);
	printf("%d \n", minSum);
}

/*
4
0 1 2 3
4 0 5 6
7 1 0 2
3 4 5 0

6
0 1 2 3 4 5
1 0 2 3 4 5
1 2 0 3 4 5
1 2 3 0 4 5
1 2 3 4 0 5
1 2 3 4 5 0
*/
