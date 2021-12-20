#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
using namespace std;

vector<pair<int, int>> pv;
int binarySearch(int low, int high, int val) {
	int mid = (low + high) / 2;
	if (low > high)
		return 0;
	if (val == pv[mid].first)
		return pv[mid].second;
	else if (pv[mid].first < val)
		return binarySearch(mid + 1, high, val);
	else
		return binarySearch(low, mid - 1, val);
}

int main() {
	int N;
	cin >> N;
	vector<int> card(N);
	for (int i = 0; i < N; i++) {
		cin >> card[i];
	}
	int M;
	cin >> M;
	vector<int> v(M);
	for (int i = 0; i < M; i++) {
		cin >> v[i];
	}

	sort(card.begin(), card.end());

	pv.push_back(make_pair(card[0], 1));
	int n = 0;
	for (int i = 1; i < N; i++) {
		if (card[i] == pv[n].first) {
			pv[n].second++;
		}
		else {
			pv.push_back(make_pair(card[i], 1));
			n++;
		}
	}
	for (int i = 0; i < M; i++)
		printf("%d ", binarySearch(0, n, v[i]));
}
/*
11
2 2 2 2 6 6 6 6 7 7 7
3
2 6 7
*/
