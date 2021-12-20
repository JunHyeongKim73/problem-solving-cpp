#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>
#include <queue>
#include <time.h>

using namespace std;

vector<int> arr;
vector<int> plain;
vector<int> tree;


int init(int node, int start, int end){
	if(start == end) // leaf node
		return tree[node] = arr[start];
	
	int mid = (start + end) / 2;
	// max
	return tree[node] = max(init(node * 2, start, mid), init(node * 2 + 1, mid + 1, end));
}

int find(int node, int start, int end, int target){
	if(target < start) return -1;
	if(end <= target) return tree[node];
	
	int mid = (start + end) / 2;
	return max(find(node * 2, start, mid, target), find(node * 2 + 1, mid + 1, end, target));
}

int update(int node, int start, int end, int index){
	if(index < start || index > end) return tree[node];
	
	if(start == end){
		return tree[node] = -1;
	}
	else{
		int mid = (start + end) / 2;
		return tree[node] = max(update(node * 2, start, mid, index), update(node * 2 + 1, mid + 1, end, index)); 
	}
}

int main(){
	int G, P;
	cin>>G;
	cin>>P;
	arr = vector<int>(G);
	plain = vector<int>(P);
	tree = vector<int>(G * 4);
	for(int i=0; i<P; i++){
		cin>>plain[i];
	}
	for(int i=0; i<G; i++){
		arr[i] = i + 1;
	}
	
	int start = clock();
	
	init(1, 0, G - 1);
	
	int end = clock();
	
	int nums = 0;
	
	for(int i=0; i<P; i++){
		int p = plain[i] - 1;
		int index = find(1, 0, G - 1, p);
		if(index == -1) break;
		else{ 
			update(1, 0, G - 1, index - 1);
			nums++;
		}
	}
	
	//int end = clock();
	
	printf("%d \n", nums);
	printf("time : %f \n", (double)end - start);
}
