#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int N, M;
int ary[9];

void solve(int n) {
	if (n == M) {
		for (int i = 0; i < M; i++)
			printf("%d ", ary[i]);
		printf("\n");
		return;
	}
	for (int i = 1; i <= N; i++) {
		ary[n] = i;
		solve(n + 1);
	}
}

int main() {
	cin >> N >> M;
	solve(0);
}
