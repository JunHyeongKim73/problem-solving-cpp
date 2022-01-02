#include <bits/stdc++.h>

using namespace std;

void Solve() {
	char c[26];
	scanf("%s", c);

	string str = c;
	int len = str.length();

	deque<char> dq;
	for(int i=0; i<len; i++) {
		dq.push_back(str[i]);
	}

	char t = 'a' + len - 1;
	while(!dq.empty()) {
		char front = dq.front(), back = dq.back();
		if(front == t) {
			dq.pop_front();
		}
		else if(back == t) {
			dq.pop_back();
		}
		else {
			printf("NO\n");
			return;
		}
		t--;
	}

	printf("YES\n");
}

int main() {
	int t;
	scanf("%d", &t);
	while(t--) {
		Solve();
	}
}