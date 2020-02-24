#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>

using namespace std;

int N, K;
vector<int> road(100001, 0);

void bfs(int start) {
	queue<int> q;
	q.push(start);
	while (!q.empty()) {
		int here = q.front();
		q.pop();
		int cost = road[here];
		if (here == K) {
			printf("%d \n", cost - 1);
			return;
		}
		if (here - 1 >= 0)
			if (road[here - 1] == 0) {
				q.push(here - 1);
				road[here - 1] = cost + 1;
			}
		if (here + 1 <= 100000)
			if (road[here + 1] == 0) {
				q.push(here + 1);
				road[here + 1] = cost + 1;
			}
		if (here * 2 <= 100000)
			if (road[here * 2] == 0) {
				q.push(here * 2);
				road[here * 2] = cost + 1;
			}
	}
}

int main() {
	cin >> N >> K;
	road[N] = 1;
	bfs(N);
}
