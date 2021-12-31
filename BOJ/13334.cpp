#include <cstdio>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int main() {
	int n;
	scanf("%d", &n);

	vector<pair<int, int>> v(n);

	for(int i=0; i<n; i++) {
		int h, o;
		scanf("%d%d", &h, &o);
		 
		if(h < o) v[i] = {o, h};
		else v[i] = {h, o};
	}

	int d;
	scanf("%d", &d);
	// 끝점을 기준으로 정렬한다.
	sort(v.begin(), v.end());
	
	// 끝점을 기준으로 정렬하는 이유는??

	// (시작점, 끝점) 순으로 변경한다.
	for(int i=0; i<n; i++) {
		int temp = v[i].first;
		v[i].first = v[i].second;
		v[i].second = temp;
	}

	priority_queue<int, vector<int>, greater<int>> pq;

	int maxs = -1;
	// 이 알고리즘이 최적해인 이유??
	// 그리디 증명 2가지 ??
	for(int i=0; i<n; i++) {
		pq.push(v[i].first);
		// 가장 작은 시작점에서 시작하는 L 영역에 새로운 선분 l이 포함되지 않으면
		// 만족하는 L 영역을 찾을때까지 우선순위 큐에서 원소를 꺼낸다.
		while(!pq.empty() && pq.top() + d < v[i].second) {
			pq.pop();
		}
		int ans = pq.size();
		maxs = max(maxs, ans);
	}

	printf("%d\n", maxs);
}
/*
8
10 40
35 25
10 20
10 25
30 50
50 60
30 25
80 100
30
*/