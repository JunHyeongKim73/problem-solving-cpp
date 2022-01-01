#include <cstdio>
#include <string>
#include <vector>
#include <algorithm>
#include <deque>

using namespace std;

int main() {
	int t;
	scanf("%d", &t);

	while(t--) {
		int n;
		scanf("%d", &n);

		vector<int> arr(n);

		for(int i=0; i<n; i++) {
			scanf("%d", &arr[i]);
		}

		sort(arr.begin(), arr.end());

		vector<pair<int, int>> ans;

		for(int i=n-1; i>=0; i--) {
			printf("%d \n", arr[i-1]);
			for(int j=0; j<arr[i-1]; j++) {
					ans.push_back({i+1, i});
			}	
			arr[i] -= arr[i-1];
			arr[i-1] = 0;
			
			for(int j=0; j<n; j++) {
				printf("%d ", arr[j]);
			}
			printf("\n");
			sort(arr.begin(), arr.end());
		}

		int len = ans.size();
		for(int i=0; i<len; i++) {
			printf("%d %d\n", ans[i].first, ans[i].second);
		}
	}
}
/*
1
4
1 2 3 4
*/