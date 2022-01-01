#include <cstdio>
#include <string>
#include <vector>
#include <algorithm>
#include <deque>

using namespace std;

void solve() {
	int n;
	scanf("%d", &n);

	vector<int> b(n+1), p(n+1), dist(n+1, -1);

	for(int i=1; i<=n; i++) {
		scanf("%d", &b[i]);
	}

	for(int i=1; i<=n; i++) {
		scanf("%d", &p[i]);
	}

	if(b[p[1]] != p[1]) {
		printf("-1\n");
		return;
	}

	dist[p[1]] = 0;
	for(int i=2; i<=n; i++) {
		if(dist[b[p[i]]] == -1) {
			printf("-1 \n");
			return;
		}
		dist[p[i]] = dist[p[i-1]] + 1;
	}

	for(int i=1; i<=n; i++) {
		printf("%d ", dist[i] - dist[b[i]]);
	}
	printf("\n");
}

int main() {
	int t;
	scanf("%d", &t);

	while(t--) {
		solve();
	}
}

/*
1
5
3 1 3 3 1
3 1 2 5 4
*/