#include <iostream>
#include <vector>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int N, M;
int ary[9];
bool visited[9];
void solve(int n) {
	if (n == M) {
		for (int i = 0; i < M; i++)
			printf("%d ", ary[i]);
		printf("\n");
		return;
	}
	for (int i = 1; i <= N; i++) {
		if (!visited[i]) {
			visited[i] = true;
			ary[n] = i;
			solve(n + 1);
			//key point
			visited[i] = false; 
		}
	}
}

int main() {
	cin >> N >> M;
	solve(0);
}
