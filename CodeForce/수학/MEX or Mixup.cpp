#include <cstdio>
#include <string>

using namespace std;

int main() {
	int t;
	scanf("%d", &t);

	while(t--) {
		int a,b;
		scanf("%d%d", &a, &b);

		int num = 0;
		if(a % 4 == 1) num = a-1;
		else if(a % 4 == 2) num = 1;
		else if(a % 4 == 3) num = a;
		else num = 0;

		if(num == b) printf("%d\n", a);
		else if((num ^ b) == a) printf("%d\n", a+2);
		else printf("%d\n", a+1);
	}
}