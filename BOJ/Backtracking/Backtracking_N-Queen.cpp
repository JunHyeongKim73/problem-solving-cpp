#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int N;
int col[15];
int ret = 0;

bool isPossible(int n) {
	for (int i = 0; i < n; i++) {
		if (col[i] == col[n] || abs(col[n] - col[i]) == (n - i))
			return false;
	}
	return true;
}

void solve(int n) {
	if (n == N) {
		ret++;
	}
	else {
		for (int i = 0; i < N; i++) {
			col[n] = i;
			if (isPossible(n))
				solve(n + 1);
		}
	}
}

int main() {
	cin >> N;
	solve(0);
	printf("%d \n", ret);
}
