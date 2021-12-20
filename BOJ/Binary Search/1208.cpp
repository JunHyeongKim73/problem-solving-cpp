#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>
#include <queue>
#include <map>

using namespace std;

int N, S;
vector<int> arr[2]; // N/2, N - N/2 배열
vector<int> sarr[2]; // sum 배열
/* 모든 합 경우의 수를 구해주는 함수 */
void solve(int sum, int start, int n){
	int last;
	if(n == 0) last = N/2;
	else last = N - N/2;
	for(int i=start+1; i<last; i++){
		sarr[n].push_back(sum + arr[n][i]);
		solve(sum + arr[n][i], i, n);
	}
}
/* 이분탐색 함수 */
bool binarySearch(int low, int high, int x){
	if(low > high)
		return false;
	int mid = (low + high) / 2;
	int mid_value = sarr[1][mid];
	if(mid_value == x) 	return true;
	else if(mid_value > x)	return binarySearch(low, mid - 1, x);
	else	return binarySearch(mid + 1, high, x);
	
}

int main(){
	scanf("%d %d", &N, &S);
	
	arr[0] = vector<int>(N/2);
	arr[1] = vector<int>(N-N/2);
	
	for(int i=0; i<N/2; i++)
		scanf("%d", &arr[0][i]);
	for(int i=0; i<N-N/2; i++){
		scanf("%d", &arr[1][i]);
	}
	
	/* sarr[0] 생성 */
	int n = 0;
	solve(0, -1, n);
	sort(sarr[n].begin(), sarr[n].end()); // sarr 오름차순 정렬
	
	/* sarr[1] 생성 */
	n = 1;
	solve(0, -1, n);
	sort(sarr[n].begin(), sarr[n].end()); // sarr 오름차순 정렬
	
	int sarr0_len = sarr[0].size();
	int sarr1_len = sarr[1].size();
	
	long long num = 0;
	/* sarr0 */
	for(int i=0; i<sarr0_len; i++){
		if(sarr[0][i] == S)
			num++;
	}
	/* sarr1 */
	for(int i=0; i<sarr1_len; i++){
		if(sarr[1][i] == S)
			num++;
	}
	
	map<int, int> m;
	/* key - value(숫자의 개수) map 초기화 */
	for(int i=0; i<sarr1_len; i++){
		int key = sarr[1][i];
		if(m[key] == 0) m[key] = 1;
		else m[key] += 1;
	}
		
	/* sarr0 + sarr1 */
	for(int i=0; i<sarr0_len; i++){
		int x = sarr[0][i];
		int y = S - x;
		if(binarySearch(0, sarr1_len - 1, y))
			num += m[y];
	}
	
	printf("%lld \n", num);
}