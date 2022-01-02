#include <bits/stdc++.h>

using namespace std;

int gcd(int a, int b) {
	if(b == 0) return a;
	return gcd(b, a%b);
}

void Solve() {
	int a, b, k;
	scanf("%d%d%d", &a, &b, &k);

	int g = gcd(a, b);

	
}

int main() {
	int t;
	scanf("%d", &t);
	while(t--) {
		Solve();
	}
}