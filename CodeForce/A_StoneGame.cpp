#include <bits/stdc++.h>

using namespace std;

void Solve() {
	int n;
	scanf("%d",&n);

	vector<int> arr(n);
	for(int i=0; i<n; i++) scanf("%d", &arr[i]);

	int mins = 101, maxs = -1;
	int minidx, maxidx;
	for(int i=0; i<n; i++) {
		if(arr[i] < mins) {
			mins = arr[i];
			minidx = i;
		}
		if(arr[i] > maxs) {
			maxs = arr[i];
			maxidx = i;
		}
	}

	int ans = min(max(minidx+1, maxidx+1), max(n-minidx, n-maxidx));
	ans = min(ans, min(minidx, maxidx) + 1 + n - max(minidx, maxidx));

	printf("%d\n", ans);
}

int main() {
	int t;
	scanf("%d", &t);
	while(t--) {
		Solve();
	}
}