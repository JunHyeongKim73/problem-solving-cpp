#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int K;
long long maxVal;
long long lan[10000];
const int INTMAX = 2147483647;
long long binarySearch(long long low, long long high, int N) {
	long long mid = (low + high) / 2;
	long long result = 0;
	if (low > high)
		return maxVal;
	for (int i = 0; i < K; i++)
		result += (lan[i] / mid);
	
	if (result >= N) {
		maxVal = mid;
		return binarySearch(mid + 1, high, N);
	}
	else
		return binarySearch(low, mid - 1, N);
}

int main() {
	int N;
	cin >> K >> N;
	for (int i = 0; i < K; i++)
		cin >> lan[i];
	
	printf("%lld \n", binarySearch(0, INTMAX, N));
}
/*
4 11
802
743
457
539
*/
