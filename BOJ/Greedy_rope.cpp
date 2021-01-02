#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(){
	int N, M;
	cin>>N;
	vector<int> v(N);
	for(int i=0; i<N; i++){
		cin>>v[i];
	}
	sort(v.begin(), v.end());
	int maxs = 0;
	for(int i=0; i<N; i++){
		if(maxs < v[i] * (N - i))
			maxs = v[i] * (N - i);
	}
	
	printf("%d \n", maxs);
	
}