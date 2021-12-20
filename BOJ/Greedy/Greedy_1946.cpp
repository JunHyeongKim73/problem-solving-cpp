#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(){
	int N;
	cin>>N;
	for(int i=0; i<N; i++){
		int M;
		cin>>M;
		vector<pair<int, int>> v(M);
		for(int j=0; j<M; j++){
			cin>>v[j].first>>v[j].second;
		}
		sort(v.begin(), v.end());
		int mins = v[0].second;
		int counts = 1;
		for(int j=0; j<M; j++){
			if(v[j].second < mins){
				counts++;
				mins = v[j].second;
			}
		}
		printf("%d \n", counts);
	}
	
}