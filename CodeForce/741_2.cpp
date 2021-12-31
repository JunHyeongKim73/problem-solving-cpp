#include <cstdio>
#include <string>
using namespace std;


int main() {
	int t;
	scanf("%d", &t);

	while(t--) {
		int k;
		scanf("%d", &k);

		char c[51];
		scanf("%s", c);

		string str = c;

		int num = 0;
		bool flag = false;
		for(int i=0; i<k; i++) {
			int num = str[i] - '0';
			if(num != 2 && num != 3 && num != 5 && num != 7) flag = true;
			if(flag){
				printf("1\n");
				printf("%c\n", str[i]);
				break;
			}
		}
		if(flag) continue;

		for(int i=0; i<k; i++) {
			int a = str[i] - '0';
			bool flag = false;
			for(int j=i+1; j<k; j++) {
				int b = str[j] - '0';
				if(10 * a + b == 23 || 10 * a + b == 37 || 10 * a + b == 53 || 10 * a + b == 73) continue;
				flag = true;
				printf("2\n");
				printf("%d\n", 10*a+b);
				break;
			}
			if(flag) break;
		}
	}
}