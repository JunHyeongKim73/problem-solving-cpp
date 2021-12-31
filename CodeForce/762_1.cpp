#include <cstdio>
#include <string>
#include <vector>
#include <algorithm>
#include <deque>
#include <numeric>
#include <cmath>

using namespace std;

void solve() {
	int n;
	scanf("%d", &n);

	vector<int> arr(n+1, 0);

	for(int i=0; i<n; i++) {
		int num;
		scanf("%d", &num);

		arr[num]++;
	}

	int mex = -1;
	for(int i=0; i<n; i++) {
		if(arr[i] == 0) break;
		mex = i+1;
	}

	int sum = 0, j = -2;
	bool flag = false;
	for(int i=0; i<=n; i++) {
		if(i == mex) printf("%d ", 0);
		else if(i < mex) printf("%d ", arr[i]);
		else {
			if(flag) {
				printf("%d ", -1);
				continue;
			}
			
			if(arr[i-1] >= 1) {
				printf("%d ", sum);
				continue;
			}

			if(j == -2) {
				for(j=i-1; j>=0; j--) {
					if(arr[j] > 1) break;
				}
			}

			if(j == -1) {
				printf("%d ", -1);
				flag = true;
				continue;
			}

			if(arr[j] <= 1) {
				for(; j>=0; j--) {
					if(arr[j] > 1) break;
				}
			}
			
			arr[j]--;
			arr[i-1] = 1;
			sum += (i-1-j);

			if(arr[i] >= 1) printf("%d ", sum + arr[i]);
			else printf("%d ", sum);
		}
	}
	printf("\n");
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
4
3 0 0 0

1
7
0 1 2 3 4 3 2
*/