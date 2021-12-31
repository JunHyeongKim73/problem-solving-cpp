#include <cstdio>
#include <vector>
#include <queue>

using namespace std;

int main() {
	int t;
	scanf("%d", &t);
	while(t--) {
		int a, b;
		scanf("%d%d", &a, &b);

		if(a > b) {
			int temp = a;
			a = b;
			b = temp;
		}

		bool visited[200001];

		queue<pair<int, int>> q;
		queue<int> qlen;
		queue<int> qbreak;
		q.push({1,1}); qlen.push(1); qbreak.push(0);
		q.push({-1, 1}); qlen.push(1); qbreak.push(1);
		q.push({2, 0}); qlen.push(1); qbreak.push(0);
		q.push({-2, 0}); qlen.push(1); qbreak.push(1);

		while(!q.empty()) {
			int x = q.front().first;
			int n = q.front().second;
			int len = qlen.front();
			int breaks = qbreak.front();
			q.pop();
			qlen.pop();
			qbreak.pop();

			if(len == a+b && n== a) {
				visited[breaks] = true;
				continue;
			}

			for(int i=0; i<2; i++) {
				int nx, nn, nbreaks;
				if(i == 0) {
					if(x < 0) nx = -3 - x;
					if(x > 0) nx = 3 - x;
				}
				if(i == 1) {
					nx = -x;
				}
				
				nn = n;
				if(nx == 1 || nx == -1) nn = n + 1;
				
				nbreaks = breaks;
				if(nx < 0) nbreaks = breaks + 1;
				if(nn > a) continue;
				if(nn + b < len + 1) continue;

				q.push({nx, nn});
				qlen.push(len+1);
				qbreak.push(nbreaks);
			}
		}

		for(int i=0; i<=a+b; i++) {
			if(visited[i]){
				printf("%d ", i);
			}
		}
		printf("\n");
	}
}

/*
1
1 2
*/