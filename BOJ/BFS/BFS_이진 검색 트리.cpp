#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>
#include <map>
using namespace std;

int main() {
	int N;
	cin >> N;
	vector<int> ary(N);
	map<long, long> ::const_iterator it;
	for (int i = 0; i < N; i++)
		cin >> ary[i];
	map<long, long> mm,mp;
	
	mm.insert({ -ary[0],0 }); mp.insert({ ary[0],0 });
	long long C = 0;
	printf("%lld \n", C);
	for (int i = 1; i < N; i++) {
		//3만 있을때 1을 삽입하는 경우
		if ((it = mm.lower_bound(-ary[i])) == mm.end()) it = mp.lower_bound(ary[i]);
		//3만 있을때 5를 삽입하는 경우
		else if ((it = mp.lower_bound(ary[i])) == mp.end()) it = mm.lower_bound(-ary[i]);
		else {
			int s = 0, b = 0;
			it = mm.lower_bound(-ary[i]); s = it->second;
			it = mp.lower_bound(ary[i]); b = it->second;
			//작은 수를 고른다
			if (s > b) it = mm.lower_bound(-ary[i]); 
			//큰 수를 고른다
			else it = mp.lower_bound(ary[i]);
		}
		long long dist = it->second;
		//printf("%d %d \n", it->first, it->second);
		mm.insert({ -ary[i],dist + 1 });
		mp.insert({ ary[i],dist + 1 });
		C += (dist + 1);
		printf("%lld \n", C);
	}
}
/*
8
3 5 1 6 8 7 2 4

10
3 5 1 9 7 6 2 8 4 10
*/
