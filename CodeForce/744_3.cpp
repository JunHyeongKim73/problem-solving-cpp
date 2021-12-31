#include <cstdio>
#include <string>
#include <vector>
#include <algorithm>
#include <deque>

using namespace std;

void solve() {
	long long n;
	scanf("%lld", &n);

	if(n % 25 == 0) {
		printf("0\n"); 
		return;
	}
	
	string str;
	while(n > 0) {
		str.push_back(n%10 + '0');
		n /= 10;
	}

	int len = str.length();
	
	int first = -1, second = -1;
	for(int i=0; i<len; i++) {
		if(!(str[i] == '5' || str[i] == '0')) continue;
		
		bool flag = false;
		for(int j=i+1; j<len; j++) {
			int num = (str[j] - '0') * 10 + (str[i] - '0');

			if((str[i] == '0' && str[j] == '0') || num % 25 == 0) {
				first = i;
				
				second = j;
				flag = true;
				break;
			}
		}

		if(flag) break;
	}

	int ans = 0;
	for(int i=0; i<second; i++) {
		if(first == i) continue;
		ans++;
	}

	printf("%d \n", ans);
	return;
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
2050047
*/