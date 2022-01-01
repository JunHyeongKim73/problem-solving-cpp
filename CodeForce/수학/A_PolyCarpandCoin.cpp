#include <bits/stdc++.h>

using namespace std;

void Solve() {
	int n;
	scanf("%d", &n);

	if(n%3 == 0) {
		printf("%d %d\n", n/3, n/3);
	}
	else if(n%3 == 1) {
		printf("%d %d\n", n/3 + 1, n/3);
	}
	else {
		printf("%d %d\n", n/3, n/3 + 1);
	}
}

int main() {
	int t;
	scanf("%d", &t);
	while(t--) {
		Solve();
	}
}