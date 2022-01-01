#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

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

		bool sort = true;
		for(int i=0; i<n-1; i++) {
			if(v[i] > v[i+1]) {
				sort = false;
				break;
			}
		}
		if(sort){
			printf("%d \n", 0);
			continue;
		}
		int num = 0;
		
		while(true) {
			int start;
			if((num + 1) % 2 == 1) {
				start = 0;
			}
			else {
				start = 1;
			}
			for(int i=start; i<n; i+=2) {
				if(i == n-1) continue;
				if(v[i+1] < v[i]) {
					int temp = v[i+1];
					v[i+1] = v[i];
					v[i] = temp;
				}
			}

			num++;

			bool sort = true;
			for(int i=0; i<n-1; i++) {
				if(v[i] > v[i+1]) {
					sort = false;
					break;
				}
			}
			if(sort) break;
		}
		printf("%d \n", num);
	}
}
/*
1
3
3 2 1
*/