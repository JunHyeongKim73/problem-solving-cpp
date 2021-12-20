#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <list>
#include <cstring>

using namespace std;

char map[102][102];
bool visited[102][102];
int H, W;
int ans;
list<pair<int, int>> door;
string key;

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};



void BFS(int start_x, int start_y){
	queue<pair<int, int>> q;
	visited[start_x][start_y] = true;
	q.push({start_x, start_y});
	
	while(!q.empty()){
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		
		for(int i=0; i<4; i++){
			int nx = x + dx[i];
			int ny = y + dy[i];
			
			if(nx == -1 || nx == H + 2 || ny == -1 || ny == W + 2) continue;
			if(map[nx][ny] == '*') continue;
			if(visited[nx][ny]) continue;
			visited[nx][ny] = true;
			/* 문 */
			if('A' <= map[nx][ny] && map[nx][ny] <= 'Z'){
				/* 문에 해당하는 열쇠가 없다면 */
				if(key.find(map[nx][ny] - ('A' - 'a')) == string::npos){
					door.push_back({nx, ny});
					continue;
				}
			}
			/* 열쇠 */
			if('a' <= map[nx][ny] && map[nx][ny] <= 'z'){
				/* 해당 열쇠를 이미 가지고 있다면 */
				if(key.find(map[nx][ny] - ('A' - 'a')) != string::npos) continue;
				key += map[nx][ny];
			}
			/* 문서 */
			if(map[nx][ny] == '$') ans++;
			
			q.push({nx, ny});
		}
	}
}

int main(){
	int t;
	scanf("%d", &t);
	while(t--){
		scanf("%d %d", &H, &W);
		for(int i=1; i<=H; i++){
			char str[101];
			scanf("%s", str);
			for(int j=1; j<=W; j++)
				map[i][j] = str[j-1];
		}
		
		char str[101];
		scanf("%s", str);
		key = str;
		if(key == "0") key = "";
		
		for(int i=0; i<=H+1; i++)
			for(int j=0; j<=W+1; j++)
				if(i == 0 || i == H+1 || j == 0 || j == W+1)
					map[i][j] = '.';
		
		queue<pair<int, int>> qu;
		qu.push({0, 0});
		/* 열쇠랑 문을 비교해서 같은게 있으면 BFS 돌림 */
		while(!qu.empty()){	
			int x = qu.front().first;
			int y = qu.front().second;
			qu.pop();
			
			BFS(x, y);
			
			list<pair<int, int>>::iterator iter;
			int len = key.length();
			
			for(int i=0; i<len; i++){
				for(iter = door.begin(); iter != door.end(); iter++)
					if(key[i] == map[iter->first][iter->second] - ('A' - 'a')){
						qu.push({iter->first, iter->second});
						iter = door.erase(iter);
						iter--;
				}
			}
			
		}
		printf("%d \n", ans);
		
		/* 초기화 */
		memset(map, 0, sizeof(map));
		memset(visited, false, sizeof(visited));
		ans = 0;
		door.clear();
		key.clear();
	}
}