#include <bits/stdc++.h>

using namespace std;

int gcd(int a, int b) {
	if(b == 0) return a;
	return gcd(b, a%b);
}

void Solve() {
	int n;
	scanf("%d", &n);

	vector<int> arr(n);
	for(int i=0; i<n; i++) scanf("%d", &arr[i]);

	int t = arr[0];
	for(int i=0; i<n; i++) {
		t = gcd(t, arr[i]);
	}

	int maxs = -1, last = 0;
	for(; last<n;) {
		int g = arr[last];
		if(g == t) {
			maxs = max(maxs, 0);
			last++;
			continue;
		}
		int j;
		for(j=1; j<n; j++) {
			g = gcd(g, arr[(last+j)%n]);
			if(g == t) {
				maxs = max(maxs, j);
				break;
			}
		}
		last += j;
	}

	printf("%d\n", maxs);
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
4
16 5 24 10
*/