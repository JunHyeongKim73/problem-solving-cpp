#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

int lunchbox(vector<pair<int, int>> pv, int n) {
	int wait = 0, cur = 0, ret = 0;
	for (int i = 0; i < n; i++) {
		wait += pv[i].second;
		ret = max(ret, wait + pv[i].first);
		
	}
	return ret;
}

int wait[10001];
int eat[10001];
int main() {
	vector<pair<int, int>> pv;
	int C;
	cin>>C;
	for (int i = 0; i < C; i++) {
		int n;
		cin >> n;
		for (int j = 0; j < n; j++)
			cin >> wait[j];
		for (int j = 0; j < n; j++)
			cin >> eat[j];
		//first: eat. second: wait
		for (int j = 0; j < n; j++)
			pv.push_back(make_pair(eat[j], wait[j]));
		sort(pv.begin(), pv.end(),greater<pair<int, int>>());
		cout << lunchbox(pv, n) << endl;
	}
}