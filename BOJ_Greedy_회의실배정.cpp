#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int N;
	cin >> N;
	vector<pair<int, int>> v;
	for (int i = 0; i < N; i++) {
		int f, l;
		cin >> f >> l;
		v.push_back(make_pair(l, f));
	}
	sort(v.begin(), v.end());
	
	int num = 0;
	int last = 0;
	for (auto it = v.begin(); it != v.end(); it++) {
		if (it == v.begin()) {
			num++;
			last = it->first;
			continue;
		}
		if (it->second >= last) {
			num++;
			last = it->first;
		}
	}
	printf("%d \n", num);
}
/*
11
1 4
3 5
0 6
5 7
3 8
5 9
6 10
8 11
8 12
2 13
12 14

9
8 8
5 8
3 4
2 5
2 7
8 8
1 10
3 3
10 10
*/
