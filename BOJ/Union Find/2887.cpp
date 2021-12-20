#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
#include <map>
using namespace std;

int N, p[100001];

void swap(int& x, int& y){
	int temp = x;
	x = y;
	y = temp;
}
/* Union-Find */
int Find(int n){
	if(p[n] == n) return p[n];
	return p[n] = Find(p[n]);
}

bool Union(int x, int y){
	x = Find(x);
	y = Find(y);
	if(x == y) return true;
	p[y] = x;
	return false;
}

int main(){
	scanf("%d",&N);
	
	vector<pair<int, int>> c[3]; //c[0] : x배열 c[1] : y배열 c[2] : z배열
	map<pair<int,int>, int> m; // ((n1, n2), dist)
	
	for(int i=0; i<N; i++){
		int x,y,z;
		scanf("%d%d%d", &x,&y,&z);
		c[0].push_back({x, i});
		c[1].push_back({y, i});
		c[2].push_back({z, i});
	}
	// x,y,z배열 정렬
	sort(c[0].begin(), c[0].end());
	sort(c[1].begin(), c[1].end());
	sort(c[2].begin(), c[2].end());
	
	for(int n=0; n<3; n++){
		for(int i=0; i<N-1; i++){
			int n1 = c[n][i].second, n2 = c[n][i+1].second; // n1, n2번째 행성 
			int c1 = c[n][i].first, c2 = c[n][i+1].first; // n1, n2번째 행성의 x|y|z좌표
			int dist = c2 - c1; // n1, n2번째 행성 x|y|z좌표의 거리
			if(n1 > n2) swap(n1, n2); // n1이 n2보다 작게 한다
			pair<int, int> p = {n1, n2};
			if(m.find(p) == m.end()) m[p] = dist;
			else m[p] = (m[p] < dist ? m[p] : dist);
		}	
	}
	
	vector<pair<int, pair<int, int>>> v; // (dist, (n1, n2))
	
	map<pair<int, int>, int>::iterator it;
	for(it=m.begin(); it!=m.end(); it++){
		int n1 = it->first.first, n2 = it->first.second;
		int dist = it->second;
		v.push_back({dist, {n1, n2}});
	}
	// dist값에 대해 정렬
	sort(v.begin(), v.end());
	
	int num = 0; 
	int sum = 0;
	for(int i=0; i<N; i++)
		p[i] = i;
	// MST 알고리즘
	for(int i=0; i<v.size(); i++){
		int n1 = v[i].second.first, n2 = v[i].second.second;
		int dist = v[i].first;
		
		if(num == N - 1) break;
		if(Union(n1, n2)) continue;
		
		num++;
		sum += dist;
	}
	printf("%d \n", sum);
}