#include <bits/stdc++.h>

using namespace std;

void Solve() {
	int xa, ya, xb, yb, xf, yf;
	scanf("%d%d", &xa, &ya);
	scanf("%d%d", &xb, &yb);
	scanf("%d%d", &xf, &yf);

	int ans = 0;
	if(xa == xb) {
		ans = abs(yb-ya);
		if((xa == xf) && ((ya < yf && yf < yb) || (yb < yf && yf < ya))) ans += 2;
	}
	else if(ya == yb) {
		ans = abs(xb-xa);
		if((ya == yf) && ((xa < xf && xf < xb) || (xb < xf && xf < xa))) ans += 2;
	}
	else{
		ans = abs(xb-xa) + abs(yb-ya);
	}

	printf("%d\n", ans);
}

int main() {
	int t;
	scanf("%d", &t);
	while(t--) {
		Solve();
	}
}