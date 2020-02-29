#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int coin[10];

int main() {
	int N, K;
	cin >> N >> K;
	for (int i = 0; i < N; i++)
		cin >> coin[i];

	int ret = 0;
	while (K > 0) {
		for (int i = N - 1; i >= 0; i--) {
			if (coin[i] <= K) {
				K -= coin[i];
				ret++;
				break;
			}
		}
	}
	printf("%d \n", ret);
}
/*
10 4200
1
5
10
50
100
500
1000
5000
10000
5000
*/
