#include <cstdio>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

const int MAX = 2000000000;

int main() {
	int t;
	scanf("%d", &t);

	while(t--) {
		int n;
		scanf("%d", &n);

		vector<int> v(n);
		for(int i=0; i<n; i++) {
			scanf("%d", &v[i]);
		}

		sort(v.begin(), v.end());

		int res = v[0];
		for(int i=1; i<n; i++) {
			res = res & v[i];
		}

		printf("%d\n", res);
	}
}

/*
1
5
1 2 3 4 5
*/