#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int C;
	cin >> C;
	while (C--) {
		int n;
		cin >> n;
		vector<int> v(n);
		vector<int> sorting(n);
		for (int i = 0; i < n; i++) {
			cin >> v[i];
			sorting[i] = v[i];
		}

		sort(sorting.begin(), sorting.end());

		int min = 0, max = n - 1;
		int start = 0, last = n - 1;

		//0부터 확인하면서 일치하는거 제외
		for (int i = 0; i < n; i++) {
			if (v[i] == sorting[i]) {
				min++; start++;
			}
			else
				break;
		}
		//n-1부터 확인하면서 일치하는거 제외
		for (int i = n - 1; i >= 0; i--) {
			if (v[i] == sorting[i]) {
				max--; last--;
			}
			else
				break;
		}
		//스왑
		int len = last - start + 1;
		int ret = 0;
		while (len > 0) {
			for (int i = 0; i < n; i++)
				cout << v[i] << " ";
			cout << endl;
			int minlen, maxlen, minpos, maxpos;
			for (int i = start; i <= last; i++) {
				if (sorting[min] == v[i]) {
					minlen = i - start;
					minpos = i;
				}
				if (sorting[max] == v[i]) {
					maxlen = last - i;
					maxpos = i;
				}
			}
			if (minlen == 0 && maxlen == 0)
				break;

			if (minlen > maxlen) {
				int i = 0;
				while (minlen > 0) {
					int temp = v[minpos - i];
					v[minpos - i] = v[minpos - i - minlen];
					v[minpos - i - minlen] = temp;
					minlen -= 2;
					i++;
				}
				min++; start++;
			}
			else {
				int i = 0;
				while (maxlen > 0) {
					int temp = v[maxpos + i];
					v[maxpos + i] = v[maxpos + i + maxlen];
					v[maxpos + i + maxlen] = temp;
					maxlen -= 2;
					i++;
				}
				max--; last--;
			}
			ret++;
		}
		printf("%d \n", ret);
	}
}

/*
1
4
3 4 1 2
*/