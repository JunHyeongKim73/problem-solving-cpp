#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int p[1001];

void swap(int& x, int& y) {
	int temp = x;
	x = y;
	y = temp;
}

/* Union-Find */
int Find(int x){
	if(p[x] == x) return x;
	return p[x] = Find(p[x]);
}

void Union(int x, int y){
	x = Find(x);
	y = Find(y);
	if(x == y) return;
	if(x > y) swap(x, y);
	p[y] = x;
}

int main() {
	int n, m;

	scanf("%d%d", &n, &m);
	
	for(int i=1; i<=n; i++) {
		p[i] = i;
	}

	for(int i=0; i<m; i++) {
		int x, y;
		scanf("%d%d", &x, &y);

		if(x > y) swap(x, y);

		Union(x, y);
	}

	for(int i=1; i<=n; i++) {
		printf("%d ", p[i]);
	}
	printf("\n");
}

/*
6 2
1 6
3 6
*/