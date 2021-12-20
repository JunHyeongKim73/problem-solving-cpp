#include <iostream>
#include <vector>

using namespace std;

int g, install = 0;
vector<int> discovered;

int gallery(vector<vector<int>> adj, int here) {
	int sub = 0, black = 0;
	discovered[here] = 1;
	for (int there = 0; there < g; there++) {
		if (adj[here][there] == 1) {
			sub++;
			adj[there][here] = 0;
			if (gallery(adj, there) == 1)
				black++;
		}
	}
	// 1: here 설치함
	// 0: here 설치 안함
	if (sub != black) {
		install++;
		return 1;
	}
	return 0;
}

int main() {
	int C;
	cin >> C;
	while (C--) {
		int h;
		cin >> g >> h;
		vector<vector<int>> adj(g, vector<int>(g + 1, 0));
		discovered = vector<int>(g, -1);
		for (int i = 0; i < h; i++) {
			int a, b;
			cin >> a >> b;
			adj[a][b] = 1;
			adj[b][a] = 1;
		}
		
		for (int i = 0; i < g; i++)
			for (int j = 0; j < g; j++)
				if (adj[i][j] == 1)
					adj[i][g]++;

		for (int i = 0; i < g; i++) {
			if (adj[i][g] == 0)
				install++;

			else if (discovered[i] == -1)
				gallery(adj, i);
		}
		cout << install << endl;
	}
}
/*
1
6 5
0 1
1 2
1 3
2 5
0 4
*/