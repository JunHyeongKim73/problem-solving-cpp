#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>
#include <queue>

using namespace std;

class C{
public:
	int a, b, n;
};

bool cmp(const C &a, const C &b){
	if(a.a < b.a) return true;
	else if(a.a == b.a && a.b > b.b) return true;
	return false;
}

int main(){
	int N, M;
	cin>>N;
	cin>>M;
	vector<C> road(M);
	for(int i=0; i<M; i++){
		cin>>road[i].a>>road[i].b;
		road[i].n = i + 1;
	}
	sort(road.begin(), road.end(), cmp);
	
	vector<bool> possible(M + 1, false);
	
	int maxs = -1;
	for(int i=0; i<M; i++){
		if(i == 0){
			possible[i + 1] = true;
			maxs = road[i].b;
			continue;
		}
		int start = road[i].a;
		int end = road[i].b;
		
		if(start > end) end += N;
		if(maxs < end){
			maxs = end;
			possible[i + 1] = true;
		}
	}
	
	for(int i=0; i<M+1; i++){
		if(possible[i])
			printf("%d ", i);
	}
	printf("\n");
}

/*
10
5
2 6
0 4
5 0
7 9
9 4

10
4
1 2
1 3
1 4
1 5
*/
