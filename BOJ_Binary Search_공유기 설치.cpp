#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
int maxDif;
vector<int> x;
const int INTMAX = 1000000000;
int binarySearch(int low, int high, int C) {
	int mid = (low + high) / 2;
	if (low > high)
		return maxDif;
	int result = 0;
	int m = 0;
	for (int i = 1; i < N; i++) {
		if ((x[i] - x[m]) >= mid) {
			result++;
			m = i;
		}
	}

	if (result >= C) {
		maxDif = mid;
		return binarySearch(mid + 1, high, C);
	}
	else
		return binarySearch(low, mid - 1, C);
}

int main() {
	int C;
	cin >> N >> C;
	x = vector<int>(N);
	for (int i = 0; i < N; i++)
		cin >> x[i];
	sort(x.begin(), x.end());
	printf("%d \n", binarySearch(0, INTMAX, C - 1));
}
