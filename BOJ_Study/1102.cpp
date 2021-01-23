#include <iostream>
#include <algorithm>
#include <cstring>
#define INF 987654321
using namespace std;

char bulb[16];
int fee[16][16];
int cache[1 << (16 + 1)];
int n, p;

int TSP(int state, int cnt)
{
	if (cnt >= p)
		return 0;

	int & ret = cache[state];
	if (ret != -1) return ret;

	ret = INF;
	
	for (int i = 0; i < n; i++)//켜진 전구를 이용해서 꺼진 전구를 켤 것임.
	{
		if ((state&(1 << i)) == 0)//꺼진 전구라면 그냥 넘어가기
			continue;
		for (int j = 0; j < n; j++)
		{
			if ((state&(1 << j)) != 0) continue;//켜진 전구라면 그냥 넘어가기
			ret = min(ret, (TSP((state | (1 << j)), cnt + 1) + fee[i][j]));
		}
	}
	return ret;
}

int main() {
	scanf("%d", &n);
	int now = 0;
	int cnt = 0;

	memset(cache, -1, sizeof(cache));

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			scanf("%d", &fee[i][j]);
		}
	}

	for (int i = 0; i < n; i++)
	{
		scanf(" %c", &bulb[i]);
		if (bulb[i] == 'Y')
		{
			now = (now | (1 << i));
			cnt += 1;
		}
	}

	scanf("%d", &p);

	if (p == 0 && cnt == 0)
	{
		printf("0\n");
	}
	else if (p != 0 && cnt == 0)
	{
		printf("-1\n");
	}
	else
		printf("%d\n", TSP(now, cnt));
}