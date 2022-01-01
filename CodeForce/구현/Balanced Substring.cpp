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

	int tnum = 0;
	for(int i=0; i<n; i++) {
		if(str[i] == '2') tnum++;
	}

	if(1<=tnum && tnum<=2) {
		printf("NO \n");
		return;
	}

	char m[51][51];
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++) {
			if(i == j) m[i][j] = 'X';
			else m[i][j] = 'a';
		}
	}

	printf("YES \n");
	for(int i=0; i<n; i++) {
		bool flag = true;
		for(int j=i+1; j<n; j++) {
			if(str[i] == '1' && str[j] == '1'){
				m[i][j] = '=';
				m[j][i] = '=';
			}
			else if(str[i] == '1' && str[j] == '2'){
				m[i][j] = '+';
				m[j][i] = '-';
			}
			else if(str[i] == '2' && str[j] == '1'){
				m[i][j] = '-';
				m[j][i] = '+';
			}
			else{
				if(flag) {
					m[i][j] = '+';
					m[j][i] = '-';
					flag = false;
				}
				else {
					m[i][j] = '-';
					m[j][i] = '+';
				}
			}
		}
		
	}

	for(int i=0; i<n; i++) {
		for(int j=0; j<n; j++) {
			printf("%c", m[i][j]);
		}
		printf("\n");
	}

	return;
}

int main() {
	int t;
	scanf("%d", &t);

	while(t--) {
		solve();
	}
}