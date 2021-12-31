#include <cstdio>
#include <vector>
#include <cmath>

using namespace std;

int main() {
	int t;
	scanf("%d", &t);

	while(t--) {
		int n;
		scanf("%d", &n);

		int odd = 0, even = 0;
		int len = 0;
		while( n > 0 ) {
			int num = n % 10;

			if((len + 1) % 2 == 0) even += num * (int)pow(10, len/2);
			else odd += num * (int)pow(10, len/2);
			
			n /= 10;
			len++;
		}

		printf("%d\n", (odd + 1) * (even + 1) - 2);
	}
}