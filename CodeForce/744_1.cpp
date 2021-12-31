#include <cstdio>
#include <string>
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

		vector<pair<int, int>> ans;
		vector<int> d;

		for(int i=0; i<n; i++) {
			int minidx = -1, mins = 2000000000;
			for(int j=0; j<n-i; j++) {
				if(mins > v[j]) {
					minidx = j;
					mins = v[j];
				}
			}
			if(minidx == 0) {
				vector<int> temp(n);
				for(int j=0; j<n-i-1; j++) {
					temp[j] = v[j+1];
				}
				v = temp;
				continue;
			}

			ans.push_back({i+1, n});
			d.push_back(minidx);

			vector<int> temp(n);
			for(int j=0; j<n-i-1; j++) {
				temp[j] = v[(minidx+j+1)%(n-i)];
			}
			v = temp;
		}

		int len = ans.size();
		printf("%d \n", len);

		for(int i=0; i<len; i++) {
			printf("%d %d %d \n", ans[i].first, ans[i].second, d[i]);
		}
	}
}
/*
1
5
2 5 1 4 3
*/