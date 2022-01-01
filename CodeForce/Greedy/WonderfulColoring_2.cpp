#include <bits/stdc++.h>

using namespace std;

void Solve() {
	int n, k;
	scanf("%d%d", &n, &k);

	map<int, vector<int>> m;
	int num = 0;
	for(int i=0; i<n; i++) {
		int a;
		scanf("%d", &a);

		if(m[a].size() < k) {
			m[a].push_back(i);
			num++;
		}
	}

	num -= num % k;

	vector<int> ans(n, 0);
	bool out = false;
	int c = 0;
	for(auto e : m) {
		for(auto idx : e.second) {
			ans[idx] = ++c;
			c %= k;
			num--;
			if(num == 0){
				out = true;
				break;
			}
		}
		if(out) break;
	}

	for(int i=0; i<n; i++) {
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
13 1
3 1 4 1 5 9 2 6 5 3 5 8 9

1
13 2
3 1 4 1 5 9 2 6 5 3 5 8 9

1
13 3
3 1 4 1 5 9 2 6 5 3 5 8 9
*/