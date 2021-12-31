#include <cstdio>
#include <string>
#include <vector>
#include <algorithm>
#include <deque>
#include <numeric>
#include <cmath>

using namespace std;

long long gcd(long long a, long long b) {
	if(b == 0) return a;
	return gcd(b, a%b);
}

void solve() {
	int n;
	scanf("%d", &n);

	vector<long long> v(n);

	for(int i=0; i<n; i++) {
		scanf("%lld", &v[i]);
	}

	long long o = v[0];
	for(int i=2; i<n; i++) {
		if(i%2 == 1) continue;
		o = gcd(o, v[i]);
	}

	long long e = v[1];
	for(int i=2; i<n; i++) {
		if(i%2 == 0) continue;
		e = gcd(e, v[i]);
	}

	long long num = o > e ? o : e;
	int val = o > e ? 0 : 1;
	for(int i=0; i<n; i++) {
		if(i%2 == val) continue;
		if(v[i] % num == 0) {
			printf("0\n");
			return;
		} 
	}

	printf("%lld\n", num);
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
5
1 2 3 4 5
*/