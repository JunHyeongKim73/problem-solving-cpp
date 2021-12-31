#include <cstdio>
#include <vector>
#include <string>

using namespace std;

void solve() {
	int n;
	scanf("%d", &n);

	char c[51];
	scanf("%s", c);

	string str = c;

	for(int i=0; i<n; i++) {
		int anum = 0, bnum = 0;
		if(str[i] == 'a') anum++;
		if(str[i] == 'b') bnum++;
		for(int j=i+1; j<n; j++) {
			if(str[j] == 'a') anum++;
			if(str[j] == 'b') bnum++;

			if(anum == bnum) {
				printf("%d %d \n", i+1, j+1);
				return;
			}
		}
	}

	printf("-1 -1\n");
}

int main() {
	int t;
	scanf("%d", &t);

	while(t--) {
		solve();
	}
}