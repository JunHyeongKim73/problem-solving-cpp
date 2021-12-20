#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

const int nMAX = 100001;
const int iMAX = 17;

int N;
vector<pair<int, int>> adj[nMAX];

bool visited[nMAX]; // dfs 함수를 위한 방문 여부 배열

int minLength[nMAX][iMAX]; // 최소 거리 저장
int maxLength[nMAX][iMAX]; // 최대 거리 저장
int parent[nMAX][iMAX]; // 부모 정보 저장
int depth[nMAX]; // 깊이 정보 저장

// 깊이, 부모, 거리 배열 초기화
void dfs(int start, int n){
	visited[start] = true;
	depth[start] = n;
	for(int i=0; i<adj[start].size(); i++){
		int next = adj[start][i].first;
		int weight = adj[start][i].second;
		
		if(visited[next]) continue;

		// next의 2^0번째 부모는 start
		parent[next][0] = start;
		// next에서 2^0번째 부모까지의 거리는 weight
		minLength[next][0] = weight;
		maxLength[next][0] = weight;
		dfs(next, n+1);
	}
}
// 부모, 거리 배열 Memoization
// 2^i번째 부모가 누구인지, 부모까지의 거리가 얼마인지 저장
void connect(){
	for(int p=1; p<iMAX; p++){
		for(int cur=1; cur<=N; cur++){
			int prevParent = parent[cur][p-1];
			parent[cur][p] = parent[prevParent][p-1];
			
			if(parent[prevParent][p-1] == 0) continue;
			
			int prevMin = minLength[prevParent][p-1];
			int prevMax = maxLength[prevParent][p-1];

			int curMin = minLength[cur][p-1];
			int curMax = maxLength[cur][p-1];

			minLength[cur][p] = min(prevMin, curMin);
			maxLength[cur][p] = max(prevMax, curMax);
		}
	}
}
// 최소 공통 조상을 찾으며 거리를 구한다
pair<int, int> LCA(int xNode, int yNode){
	if(depth[xNode] > depth[yNode]){
		int temp = xNode;
		xNode = yNode;
		yNode = temp;
	}
	int mins = 1000001;
	int maxs = -1;
	// 두 노드의 높이를 맞춰준다
	for(int i=iMAX-1; i>=0; i--){
		int jump = 1 << i;
		if(depth[yNode] - depth[xNode] >= jump){
			// 최대 최소 길이를 갱신한다
			mins = min(mins, minLength[yNode][i]);
			maxs = max(maxs, maxLength[yNode][i]);
			yNode = parent[yNode][i];
		}
	}
	// 두 노드가 같다면 종료한다
	if(xNode == yNode) return {mins, maxs};
	// 같지 않으면 같을 때까지 올라가며 검사한다
	for(int i=iMAX-1; i>=0; i--){
		if(parent[xNode][i] == parent[yNode][i]) continue;
		
		// 최대 최소 길이를 갱신한다
		mins = min(mins, min(minLength[xNode][i], minLength[yNode][i]));
		maxs = max(maxs, max(maxLength[xNode][i], maxLength[yNode][i]));
		
		xNode = parent[xNode][i];
		yNode = parent[yNode][i];
	}
	// 최대 최소 길이를 갱신한다
	mins = min(mins, min(minLength[xNode][0], minLength[yNode][0]));
	maxs = max(maxs, max(maxLength[xNode][0], maxLength[yNode][0]));

	return {mins, maxs};
}

int main() {
	scanf("%d", &N);
	// 트리를 만든다
	for(int i=0; i<N-1; i++) {
		int A, B, C;
		scanf("%d%d%d", &A, &B, &C);

		adj[A].push_back({B, C});
		adj[B].push_back({A, C});
	}

	int K;
	scanf("%d", &K);
	vector<pair<int, int>> ans(K);
	for(int i=0; i<K; i++) {
		int D, E;
		scanf("%d%d", &D, &E);
		ans[i] = {D, E};
	}
	// LCA를 위한 전처리
	dfs(1, 0);
	connect();

	for(int i=0; i<K; i++) {
		int x = ans[i].first;
		int y = ans[i].second;

		pair<int, int> ans = LCA(x, y);
		printf("%d %d\n", ans.first, ans.second);
	}
}

/*
5
2 3 100
4 3 200
1 5 150
1 3 50
3
2 4
3 5
1 2
*/