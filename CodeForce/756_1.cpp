#include <cstdio>
#include <string>
#include <vector>
#include <algorithm>
#include <deque>

#define MAX 2000000
#define MIN -2000000

using namespace std;

void solve() {
	int a, b;
	scanf("%d%d", &a, &b);

	if(a < b) {
		int temp = a;
		a = b;
		b = temp;
	}

	int num = 0;
	
	if(a==0 || b == 0){
		printf("0 \n");
		return;
	}

	if((a/b) >= 3) {
		num += b;
		a -= b * 3;
		b = 0;
	}
	else {
		int c = (a - b) / 2;
		num += c;
		num += (b - c) / 2; 
	}

	printf("%d \n", num);
}

int main() {
	int t;
	scanf("%d", &t);

	while(t--) {
		solve();
	}
}

/*
1
3 3
RRDLUU

1
4 3
LUURRDDLLLUU
*/