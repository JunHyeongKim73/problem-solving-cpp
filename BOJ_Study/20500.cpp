#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>
#include <queue>

using namespace std;

int N;
const int DIV = 1000000007;
long long cache[1516][1516];

long long com(int n, int r){
	for(int i=0; i<=n; i++){
		for(int j=0; j<=r; j++){
			if(i == j || i == 0 || j == 0) cache[i][j] = 1;
			else cache[i][j] = (cache[i - 1][j - 1] + cache[i - 1][j]) % DIV;
		}
	}
	return cache[n][r];
}

int main(){
	cin>>N;
	
	int x, y; // x는 5의 개수 y는 1의 개수;
	long long result = 0;
	for(int i=0; i<N; i++){
		x = i + 1, y = N - x;
		if((5 * x + y) % 3 != 0) continue;
		int r = (x - 1 < y ? x - 1 : y);
		result = (result + com(N - 1, r)) % DIV;
	}
	
	printf("%lld \n", result);
}