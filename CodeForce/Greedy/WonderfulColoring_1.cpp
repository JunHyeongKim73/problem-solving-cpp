#include <bits/stdc++.h>

using namespace std;

void Solve() {
	char c[51];
	scanf("%s", c);

	string str = c;

	int count[26] = {0}, len = str.length();
	for(int i=0; i<len; i++) {
		count[str[i]-'a']++;
	}

	int n = 0, e = 0;
	for(int i=0; i<26; i++) {
		if(count[i] == 0) continue;
		if(count[i] > 1) n++;
		else e++;
	}

	printf("%d\n", n+e/2);
}

int main() {
	int t;
	scanf("%d", &t);
	while(t--) {
		Solve();
	}
}

/*
1
codeforces
*/