#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>
#include <queue>

using namespace std;

vector<int> arr;

int zero_num = 0;
int num = 0;

void update(int start, int end, int k){
	num += abs(k);
	for(int i=start; i<=end; i++){
		arr[i] -= k;
		if(arr[i] == 0) zero_num++;
	}
}

int main(){
	int N;
	cin>>N;
	vector<int> cur(N);
	vector<int> cor(N);
	arr = vector<int>(N);
	for(int i=0; i<N; i++) cin>>cur[i];
	for(int i=0; i<N; i++) cin>>cor[i];
	for(int i=0; i<N; i++) arr[i] = cor[i] - cur[i];
	
	for(int i=0; i<N; i++)
		if(cur[i] == cor[i])
			zero_num++;
	
	while(zero_num != N){
		for(int i=0; i<N; i++){
			int mins = 100;
			int maxs = -100;
			int k = i;
			
			if(arr[i] == 0) continue;
			else if(arr[i] > 0){
				mins = arr[i];
				for(int j=i+1; j<N; j++){
					if(arr[j] <= 0) break;
					else{
						k = j;
						mins = min(mins, arr[j]);
					}
				}
				update(i, k, mins);	
				break;
			}
			else{
				maxs = arr[i];
				for(int j=i+1; j<N; j++){
					if(arr[j] >= 0) break;
					else{
						k = j;
						maxs = max(maxs, arr[j]);
					}
				}
				update(i, k, maxs);
				break;
			}
		}
	}
	
	printf("%d \n", num);
}

/*
	4
	0 0 0 0
	2 1 1 2
	
	4
	1 2 3 4
	3 1 1 0
	
	4
	0 0 0 0
	2 1 0 2
	
	4
	1 1 1 1
	1 1 1 1
	
	4
	1 2 3 4
	3 1 4 1
	
	4
	0 0 0 0
	0 1 2 3
	
	5
	0 0 0 0 0
	1 2 3 4 5
	
	5
	0 0 0 0 0
	5 4 3 2 1
	*/