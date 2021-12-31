#include <cstdio>
#include <string>
#include <vector>
#include <algorithm>
#include <deque>

#define MAX 2000000
#define MIN -2000000

using namespace std;

void solve() {
	int n, m;
	scanf("%d%d", &n, &m);

	char c[1000001];
	scanf("%s", c);

	string str = c;

	int len = str.length();
	int xmins = 0, xmaxs = 0;
	int ymins = 0, ymaxs = 0;
	int x = 0, y = 0;
	for(int i=0; i<len; i++) {
		if(str[i] == 'R') {
			x += 1;
		}
		else if(str[i] == 'L') {
			x -= 1;
		}
		else if(str[i] == 'U'){
			y -= 1;
		}
		else {
			y += 1;
		}
		if((x-xmins) >= m || (xmaxs - x) >= m || (y-ymins) >= n || (ymaxs-y) >= n) break;
		
		xmins = min(xmins, x);
		xmaxs = max(xmaxs, x);
		ymins = min(ymins, y);
		ymaxs = max(ymaxs, y);
	}	

	printf("%d %d \n", 1-ymins, 1-xmins);
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
3 3
RRDLUU

1
4 3
LUURRDDLLLUU
*/