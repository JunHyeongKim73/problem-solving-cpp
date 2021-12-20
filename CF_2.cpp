#include <cstdio>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>

using namespace std;

int dx[2] = {1, -1};

int main() {
	int t;
	scanf("%d", &t);

	while(t--) {
		int n;
		scanf("%d", &n);

		vector<int> v(n+2);

		for(int i=1; i<=n; i++) {
			scanf("%d", &v[i]);
		}
		v[0] = 0;
		v[n+1] = 1;

		bool flag = false;
		for(int i=0; i<n+1; i++) {
			if(v[i+1] - v[i] == 1){
				flag = true;
			}
		}

		if(flag) {
			bool clear = false;
			for(int i=0; i<=n; i++) {
				if(i != 0){
					printf("%d ", i);
				}
				if(v[i+1] - v[i] == 1 && !clear) {
					clear = true;
					printf("%d ", n+1);
				}
			}
			printf("\n");
		}
		else {
			printf("%d\n", -1);
		}
	}
}

/*
1
5
0 1 0 0 0
*/