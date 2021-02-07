#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>
#include <queue>

using namespace std;

int N, M;
int arr[100001];
int tree[400010];

void makeTree(int low, int high, int n){
	if(low == high){
		tree[n] = arr[low];
		return;
	}
	int mid = (low + high) / 2;
	makeTree(low, mid, 2 * n);
	makeTree(mid + 1, high, 2 * n + 1);
	tree[n] = min(tree[2 * n], tree[2 * n + 1]);
}

int solve(int low, int high, int left, int right, int n){
	if(left > high || right < low) return - 1;
	if(left <= low && high <= right) return tree[n];
	int mid = (low + high) / 2;
	int r1 = solve(low, mid, left, right, 2 * n);
	int r2 = solve(mid + 1, high, left, right, 2 * n + 1);
	if(r1 == - 1) return r2;
	else if (r2 == - 1) return r1;
	else return min(r1, r2);
}

int main(){
	cin>>N>>M;
	for(int i=0; i<N; i++) cin>>arr[i+1];
	
	makeTree(1, N, 1);
	
	for(int i=0; i<M; i++){
		int a, b;
		scanf("%d", &a);
		scanf("%d", &b);
		int ans = solve(1, N, a, b, 1);
		printf("%d \n", ans);
	}
}

/*
10 4
75
30
100
38
50
51
52
20
81
5
1 10
3 5
6 9
8 10

4 2
10
75
30
100
1 2
2 4
*/