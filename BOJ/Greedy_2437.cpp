#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>

using namespace std;

int N;
vector<int> v;

int main(){
	cin>>N;
	v = vector<int>(N);
	for(int i=0; i<N; i++){
		cin>>v[i];
	}
	sort(v.begin(), v.end());
	
	int sums = 0;
	for(int i=0; i<N; i++){
		if(sums + 1 < v[i]) break;
		sums += v[i];	
	}
	printf("%d \n", sums + 1);
}