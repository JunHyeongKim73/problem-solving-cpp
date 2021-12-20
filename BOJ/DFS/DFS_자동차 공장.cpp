#include <iostream>
#include <vector>
using namespace std;
vector<int> salary, s, e, lazy, seg;
int N, M, c = 0;
vector<vector<int>> vt; // tree
//각 노드들의 starting point와 ending point를 저장
void dfs(int here) {
	s[here] = ++c;
	for (int next : vt[here])
		if (!s[next]) dfs(next);
	e[here] = c;
}
//lazy에 저장되어 있던 값들을 자식들에게 보낸다
void u_lazy(int node, int x, int y) {
	if (!lazy[node]) return;
	seg[node] += lazy[node] * (y - x + 1);
	if (x != y) {
		lazy[node * 2] += lazy[node];
		lazy[node * 2 + 1] += lazy[node];
	}
	lazy[node] = 0;
}
//(x,y)는 segment tree 노드의 범위(1-6,1-3,4-6...)
//(lo,hi)는 update하려는 부분합(3-6)
int update(int lo, int hi, int val, int node, int x, int y) {
	u_lazy(node, x, y);
	if (y < lo || hi < x) return seg[node];
	if (lo <= x && y <= hi) {
		lazy[node] += val;
		u_lazy(node, x, y);
		return seg[node];
	}
	int mid = (x + y) >> 1; // (x + y) / 2
	//자식들의 합
	return seg[node] = update(lo, hi, val, node * 2, x, mid) + update(lo, hi, val, node * 2 + 1, mid + 1, y);
}

int query(int lo, int hi, int node, int x, int y) {
	u_lazy(node, x, y);
	//(lo,hi)범위를 벗어난거면
	if (y < lo || hi < x) return 0;
	if (lo <= x && y <= hi) return seg[node];
	int mid = (x + y) >> 1; // (x + y) / 2
	return query(lo, hi, node * 2, x, mid) + query(lo, hi, node * 2 + 1, mid + 1, y);
}

int main() {
	cin >> N >> M;
	vt.resize(N + 1), salary.resize(N + 1), s.resize(N + 1), e.resize(N + 1), lazy.resize(N * 4), seg.resize(N * 4);
	for (int i = 1; i <= N; i++) {
		cin >> salary[i];
		if (i != 1) {
			int x;
			cin >> x;
			vt[x].push_back(i);
		}
	}
	dfs(1);
	//segment tree 초기화
	for (int i = 1; i <= N; i++)
		update(s[i], s[i], salary[i], 1, 1, N);
	
	for (int i = 0; i < M; i++) {
		int x, y;
		char c;
		cin >> c;
		if (c == 'p') {
			cin >> x >> y;
			if (s[x] == e[x]) continue;
			
			printf("\n");
			for (int j = 1; j < seg.size(); j++)
				printf("%d %d \n", j, seg[j]);
			update(s[x] + 1, e[x], y, 1, 1, N);
			printf("\n");
			for (int j = 1; j < seg.size(); j++)
				printf("%d %d \n", j, seg[j]);
		}
		else {
			cin >> x;
			printf("%d \n", query(s[x], s[x], 1, 1, N));
		}
	}
}
/*
6 7
5
4 1
3 2
7 3
2 3
3 5
p 3 2
p 2 4
u 3
u 6
p 5 -2
u 6
u 1
*/
reference: https://jason9319.tistory.com/235
