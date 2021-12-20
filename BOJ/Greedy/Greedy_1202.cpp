#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>
#include <queue>

using namespace std;

int N, K;

int main(){
	cin>>N>>K;
	vector<pair<int, int>> jew(N);
	vector<int> bag(K);
	priority_queue<int, vector<int>, less<int>> pq;
	for(int i=0; i<N; i++){
		cin>>jew[i].first>>jew[i].second;
	}
	for(int i=0; i<K; i++){
		cin>>bag[i];
	}
	
	sort(jew.begin(), jew.end());
	sort(bag.begin(), bag.end());
	
	int cur = 0;
	long long sums = 0;
	for(int i=0; i<K; i++){
		for(cur; cur<N; cur++){
			if(jew[cur].first<=bag[i]) pq.push(jew[cur].second);
			else break;
		}
		if(!pq.empty()){
			sums += pq.top();
			pq.pop();
		}
	}
	printf("%lld \n", sums);
}