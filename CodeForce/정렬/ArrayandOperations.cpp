#include <bits/stdc++.h>

using namespace std;

void solve() {
	int n, k;
	scanf("%d%d", &n, &k);

	vector<int> v(n);
	for(int i=0; i<n; i++) {
		scanf("%d", &v[i]);
	}

	sort(v.begin(), v.end());
	
	int ans = 0;
	for(int i=0; i<n-2*k; i++) {
		ans += v[i];
	}

	int num = 0;
	for(int i=0; i<k; i++) {
		ans += (v[n-2*k + i] / v[n-k + i]);
	}

	printf("%d\n", ans);
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
9 3
1 1 2 3 7 10 10 10 10
*/