#include <bits/stdc++.h>

using namespace std;

void Solve() {
	int k, n, m;
	scanf("%d%d%d", &k, &n, &m);

	vector<int> a(n+1, -1), b(m+1, -1);
	for(int i=0; i<n; i++) scanf("%d", &a[i]);
	for(int i=0; i<m; i++) scanf("%d", &b[i]);

	int pa = 0, pb = 0, swap = 0, turn = 0;
	vector<int> ans;
	while(pa + pb < n + m) {
		// printf("%d %d %d\n", pa, pb, turn);
		if(swap == 2) {
			printf("-1\n");
			return;
		}
		if(turn == 0) {
			if(a[pa] == -1 || a[pa] > k) {
				turn = 1;
				swap++;
				continue;
			}
			if(a[pa] == 0) {
				k++;
			}

			swap = 0;
			ans.push_back(a[pa]);
			pa++;
		}
		else {
			if(b[pb] == -1 || b[pb] > k) {
				turn = 0;
				swap++;
				continue;
			}
			if(b[pb] == 0) {
				k++;
			}

			swap = 0;
			ans.push_back(b[pb]);
			pb++;
		}
	}

	int len = ans.size();
	for(int i=0; i<len; i++) {
		printf("%d ", ans[i]);
	}
	printf("\n");
}

int main() {
	int t;
	scanf("%d", &t);
	while(t--) {
		Solve();
	}
}

/*
1
5 4 4
6 0 8 0
0 7 0 9
*/