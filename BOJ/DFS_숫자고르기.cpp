#include <iostream>
using namespace std;

int ary[101], N;
bool visited[101];

int dfs(int start, int first, int n) {
	int next = ary[start];
	visited[start] = true;
	if (next == first) return n;
	if (!visited[next]) {
		int res = dfs(next, first, n + 1);
		if (res == 0) visited[start] = false;
		else return res;
	}
	visited[start] = false;
	return 0;
}

int dfsAll() {
	int sum = 0;
	for (int i = 1; i <= N; i++)
		if (!visited[i]) {
			sum += dfs(i, i, 1);
		}
	return sum;
}

int main() {
	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> ary[i + 1];
	int ret = dfsAll();

	printf("%d \n", ret);

	for (int i = 1; i <= N; i++)
		if (visited[i])	
			printf("%d\n", i);
}
/*
7
3 1 1 5 5 4 6

4
2 3 4 1

9
5 6 2 8 3 4 2 7 6
*/
