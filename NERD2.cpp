#include <iostream>
#include <vector>
using namespace std;
int ary[50001], N;
int main() {
	int C; cin >> C;
	while (C--) {
		cin >> N;
		for (int i = 0; i < N; i++)
			cin >> ary[i];
		vector<int> v, vector<int> ans(N, 0);
		for (int i = 0; i < N; i++)
			v.push_back(i + 1);
		for (int len = N - 1; len >= 0; len--) {
			ans[len] = v[len - ary[len]];
			v.erase(v.begin() + len - ary[len]);
		}
		for (int i = 0; i < N; i++)
			cout << ans[i] << " ";
		cout << endl;
	}
}