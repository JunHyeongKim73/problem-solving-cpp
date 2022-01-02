#include <bits/stdc++.h>

using namespace std;

int rev(int n, int prev) {
	int len = log2(max(n, prev)) + 1;
	int sum = pow(2, len) - 1;
	int ans = (sum - n) & prev;

	return ans;	
}

void Solve() {
	int n;
	scanf("%d", &n);

	vector<int> arr(n);
	for(int i=0; i<n; i++) scanf("%d", &arr[i]);

	if(n == 1) {
		printf("0\n");
		return;
	}

	vector<int> ans;
	ans.push_back(0);
	int prev = arr[0];
	for(int i=1; i<n; i++) {
		int num = rev(arr[i], prev);
		prev = arr[i] ^ num;
		ans.push_back(num);
	}

	for(int i=0; i<ans.size(); i++) {
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
4
11 13 15 1
*/