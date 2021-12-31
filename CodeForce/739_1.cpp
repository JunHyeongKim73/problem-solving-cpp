#include <cstdio>
#include <string>
#include <vector>
#include <algorithm>
#include <deque>
#include <numeric>
#include <cmath>
#include <limits>

using namespace std;

const int MIN = 111;

string str;
int len;

int DFS(string s, int idx, int n) {
	printf("%s %d %d\n",s.c_str(), idx, n);
	if(n >= len) return MIN;
	int mins = MIN;

	int num = stoi(s);
	int bf = s.length();
	int af = to_string(num).length();
	
	if((num & (num - 1)) == 0) {
		mins = min(mins, (len - n) + (bf - af));
	}

	for(int i=idx+1; i<len; i++) {
		s += str[i];
		mins = min(mins, DFS(s, i+1, n+1));
		s.pop_back();
	}

	for(int i=0; i<10; i++) {
		s += (i + '0');
		mins = min(mins, DFS(s, idx+1, n+1));
		s.pop_back();
	}
	
	return mins;
}

void solve() {
	char c[10];
	scanf("%s", c);

	str = c;
	len = str.size();

	int mins = MIN;
	for(int i=0; i<len; i++) {
		string s(1, str[i]);
		mins = min(mins, DFS(s, i, 1));
	}

	if(mins == MIN) {
		printf("%d \n", len + 1);
		return;
	}

	printf("%d \n", mins);
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
687194767
*/