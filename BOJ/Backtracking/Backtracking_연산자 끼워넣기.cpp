#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int	ary[11];
int oper[4];
int op[10];
int N;

int max_num = -2000000000;
int min_num = 2000000000;

void solve(int n, int ret) {
	if (n == N) {
		if (max_num < ret)
			max_num = ret;
		if (min_num > ret)
			min_num = ret;
		return;
	}
	for (int i = 0; i < N - 1; i++) {
		if (op[i] == 0) {
			op[i] = -1;
			solve(n + 1, ret + ary[n]);
			op[i] = 0;
		}
		else if (op[i] == 1) {
			op[i] = -1;
			solve(n + 1, ret - ary[n]);
			op[i] = 1;
		}
		else if (op[i] == 2) {
			op[i] = -1;
			solve(n + 1, ret * ary[n]);
			op[i] = 2;
		}
		else if (op[i] == 3) {
			op[i] = -1;
			solve(n + 1, ret / ary[n]);
			op[i] = 3;
		}
	}
}

int main(void){
	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> ary[i];
	for (int i = 0; i < 4; i++)
		cin >> oper[i];
	int n = 0;
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < oper[i]; j++)
			op[n++] = i;
	}
	solve(1, ary[0]);
	printf("%d \n", max_num);
	printf("%d \n", min_num);
	return 0;
}
/*
2
5 6
0 0 1 0

3
3 4 5
1 0 1 0

6
1 2 3 4 5 6
2 1 1 1
*/
