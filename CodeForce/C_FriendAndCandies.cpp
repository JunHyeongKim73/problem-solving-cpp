#include <bits/stdc++.h>

using namespace std;

void Solve() {
	int n;
	scanf("%d", &n);

	vector<int> arr(n);
	for(int i=0; i<n; i++) scanf("%d", &arr[i]);

	int sum = 0;
	for(int i=0; i<n; i++) {
		sum += arr[i];
	}

	if(sum % n != 0) {
		printf("-1\n");
		return;
	}

	int d = sum / n;
	int num = 0;
	for(int i=0; i<n; i++) {
		if(arr[i] > d) num++;
	}

	printf("%d\n", num);
}

int main() {
	int t;
	scanf("%d", &t);
	while(t--) {
		Solve();
	}
}