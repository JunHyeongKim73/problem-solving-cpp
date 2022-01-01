#include <cstdio>
#include <string>

using namespace std;

int main() {
	int t;
	scanf("%d", &t);

	while(t--) {
		int n;
		scanf("%d", &n);

		char c[101];
		scanf("%s", c);

		string str = c;

		for(int i=0; i<n; i++) {
			if(str[i] == 'U') printf("D");
			else if(str[i] == 'D') printf("U");
			else printf("%c", str[i]);
		}
		printf("\n");
	}
}