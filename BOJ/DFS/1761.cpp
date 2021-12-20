#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>

using namespace std;

const int nMAX = 40001;
const int iMAX = 16;
int N;

vector<pair<int, int>> adj[nMAX]; // 가중치 그래프를 인접 리스트로 표현
bool visited[nMAX]; // dfs 함수를 위한 방문 여부 배열

int length[nMAX][iMAX]; // 거리 정보 저장
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
		
		parent[next][0] = start;
		length[next][0] = weight;
		dfs(next, n+1);
	}
}
// 부모, 거리 배열 Memoization
void connect(){
	for(int p=1; p<iMAX; p++){
		for(int cur=1; cur<=N; cur++){
			int prevParent = parent[cur][p-1];
			parent[cur][p] = parent[prevParent][p-1];
			
			if(parent[prevParent][p-1] == 0) continue;
			
			int prevLength = length[cur][p-1];
			length[cur][p] = prevLength + length[prevParent][p-1];
		}
	}
}
// 최소 공통 조상을 찾으며 거리를 구한다
int LCA(int xNode, int yNode){
	if(depth[xNode] > depth[yNode]){
		int temp = xNode;
		xNode = yNode;
		yNode = temp;
	}
	int lenSum = 0;
	// 두 노드의 높이를 맞춰준다
	for(int i=iMAX-1; i>=0; i--){
		int jump = 1 << i;
		if(depth[yNode] - depth[xNode] >= jump){
			lenSum += length[yNode][i];
			yNode = parent[yNode][i];
		}
	}
	// 두 노드가 같다면
	if(xNode == yNode) return lenSum;
	// 같지 않으면 같을 때까지 올라가며 검사한다
	for(int i=iMAX-1; i>=0; i--){
		if(parent[xNode][i] == parent[yNode][i]) continue;
		
		lenSum += length[xNode][i];
		xNode = parent[xNode][i];
		
		lenSum += length[yNode][i];
		yNode = parent[yNode][i];
	}
	
	lenSum += length[xNode][0] + length[yNode][0];
	return lenSum;
}

int main(){
	scanf("%d",&N);
	for(int i=1; i<N; i++){
		int s,e,w;
		scanf("%d %d %d",&s,&e,&w);
		
		adj[s].push_back({e,w});
		adj[e].push_back({s,w});
	}
	
	int M;
	int ans[10001][2];
	
	scanf("%d",&M);
	for(int i=0; i<M; i++){
		scanf("%d %d", &ans[i][0], &ans[i][1]);
	}
	
	dfs(1, 0);
	connect();
		
	for(int i=0; i<M; i++){
		// 노드 1, 노드 2
		int x = ans[i][0], y = ans[i][1];
		printf("%d \n", LCA(x, y));
	}
}

//https://exponential-e.tistory.com/34 참고