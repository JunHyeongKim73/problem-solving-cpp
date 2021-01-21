#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>
#include <queue>

using namespace std;

int N;

int one = 0, two = 0, three = 0;

void dnq(int left, int right, int f, int n){
	double n1 = pow(3, n);
	double n2 = pow(3, n - 1);
	if(left == 0 && right == n1 - 1){
		int num[4] = {0};
		num[f] = 1;
		for(int i=0; i<n; i++){
			int a = num[1] + 2 * num[2];
			int b = num[1] + num[2] + 2 * num[3];
			int c = num[1] + num[3];
			num[1] = a; num[2] = b; num[3] = c;
		}
		one += num[1];
		two += num[2];
		three += num[3];
		return;
	}
	
	int num[3];
	if(f == 1){
		num[0] = 1; num[1] = 3; num[2] = 2;
	}
	if(f == 2){
		num[0] = 2; num[1] = 1; num[2] = 1;
	}
	if(f == 3){
		num[0] = 2; num[1] = 3; num[2] = 2;
	}
	// 한 구간에만 속하는 경우
	if(right < n2)							dnq(left, right, num[0], n - 1);
	else if(n2 <= left && right < n2 * 2) 	dnq(left - int(n2), right - int(n2), num[1], n - 1);
	else if(n2 * 2 <= left)					dnq(left - int(2 * n2), right - int(2 * n2), num[2], n - 1);
	
	// 두 구간에 속하는 경우
	if((0 <= left && left < n2) && (n2 <= right && right < n2 * 2)){
		dnq(left, n2 - 1, num[0], n - 1);
		dnq(0, right - int(n2), num[1], n - 1);
	}
	
	else if((n2 <= left && left < n2 * 2) && (n2 * 2 <= right && right < n1)){
		dnq(left - int(n2), n2 - 1, num[1], n - 1);
		dnq(0, right - int(n2 * 2), num[2], n - 1);
	}
	
	// 세 구간에 속하는 경우
	if((0 <= left && left < n2) && (n2 * 2 <= right && right < n1)){
		dnq(left, n2 - 1, num[0], n - 1);
		dnq(0, n2 - 1, num[1], n - 1);
		dnq(0, right - int(n2 * 2), num[2], n - 1);
	}
}

int main(){
	int F;
	cin>>F;
	int left, right;
	cin>>left>>right;
	cin>>N;
	
	dnq(left, right, F, N);
	
	printf("%d %d %d \n", one, two, three);
}

/*
1 0 2 2

1 3 5 2

1 6 8 2

1 0 5 2

1 3 8 2

1 2 6 2

1 0 26 3
*/