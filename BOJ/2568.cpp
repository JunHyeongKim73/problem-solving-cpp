#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
#include <map>
using namespace std;

int N;
vector<pair<int, int>> arr; // 전봇대 (A, B)를 저장하는 배열
vector<int> sarr; // 전봇대 A를 정렬했을 때의 전봇대 B 배열
map<int, int> m; // (key, value) == 전봇대 (B, A)

int main(){
	scanf("%d", &N);
	arr = vector<pair<int, int>>(N);
	sarr = vector<int>(N);
	
	for(int i=0; i<N; i++){
		int key, value;
		scanf("%d %d", &value, &key);
		arr[i].first = value;
		arr[i].second = key;
		m[key] = value;
	}
	
	sort(arr.begin(), arr.end());
	
	for(int i=0; i<N; i++){
		sarr[i] = arr[i].second;
	}
	
	vector<int> v; // 이분탐색을 진행하는 배열
	vector<int> iarr; // 배열에 추가되는 숫자의 인덱스를 저장하는 배열
	
	for(int i=0; i<N; i++){
		if(i == 0){
			v.push_back(sarr[i]);
			iarr.push_back(1);
			continue;
		}
		int idx = lower_bound(v.begin(), v.end(), sarr[i]) - v.begin();
		int len = v.size();
		// 추가하는 숫자가 가장 마지막 숫자보다 크다면
		if(idx == len) v.push_back(sarr[i]);
		else v[idx] = sarr[i]; // 않다면 교체
		iarr.push_back(idx + 1); // 인덱스 배열에 인덱스 넣기
	}
	
	int len = v.size();
	vector<int> ans(len); // LIS 배열
	// LIS를 구하는 과정
	for(int i=N-1, n=len; i>=0; i--){
		if(iarr[i] == n)
			ans[--n] = sarr[i];
	}
	// LIS에 속하는 숫자를 제하는 과정
	for(int i=0; i<len; i++){
		m[ans[i]] = -1;
	}
	
	printf("%d \n", N - len);
	for(int i=0; i<N; i++){
		int key = sarr[i];
		if(m[key] == -1) continue;
		printf("%d \n", m[key]);
	}
}