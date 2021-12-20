#include <iostream>
#include <queue>

using namespace std;

int ary[101];

int strJoin(int n) {
	priority_queue<int, vector<int>, greater<int>> pq;
	for (int i = 0; i < n; i++) {
		pq.push(ary[i]);
	}
	int ret = 0;
	while (pq.size() != 1) {
		int s1 = pq.top(); pq.pop();
		int s2 = pq.top(); pq.pop();
		ret += s1 + s2;
		pq.push(s1 + s2);
	}
	return ret;
}

int main() {
	int C;
	cin >> C;
	for (int i = 0; i < C; i++) {
		int n;
		cin >> n;
		for (int j = 0; j < n; j++)
			cin >> ary[j];
		cout << strJoin(n) << endl;
	}
}