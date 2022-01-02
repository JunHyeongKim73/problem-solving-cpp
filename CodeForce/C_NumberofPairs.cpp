#include <bits/stdc++.h>

using namespace std;

void Solve() {
	int n, l, r;
	scanf("%d%d%d", &n, &l, &r);

	vector<int> arr(n);
	for(int i=0; i<n; i++) scanf("%d", &arr[i]);

	sort(arr.begin(), arr.end());

	long long sum = 0;
	for(int i=0; i<n; i++) {
		int lidx = lower_bound(arr.begin(), arr.end(), l - arr[i]) - arr.begin();
		int ridx = upper_bound(arr.begin(), arr.end(), r - arr[i]) - arr.begin();
		
		sum += max(ridx - max(lidx, i+1), 0);
	}

	printf("%lld\n", sum);
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
5 9 12
2 4 6 8 10
*/