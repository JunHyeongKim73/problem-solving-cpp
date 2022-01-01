# include <cstdio>

using namespace std;

int main() {
	int t;
	scanf("%d", &t);

	while(t--) {
		int l, r;
		scanf("%d%d", &l, &r);

		int num = r / 2;
		if(r % 2 == 1) num++;

		int ans;
		if(l > num) ans = r % l;
		else ans = num - 1;

		printf("%d\n", ans);
	}
}