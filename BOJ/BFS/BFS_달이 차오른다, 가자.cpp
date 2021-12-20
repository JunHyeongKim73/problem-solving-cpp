#include <iostream>
#include <queue>
using namespace std;

struct maze {
    int x, y, k;
};

int N, M, sx, sy;
char a[50][50];

//열쇠를 여러번 사용할 수 있으므로 비트를 이용하는 것이 바람직
int dist[50][50][1<<6];
//동 서 남 북
const int dx[] = { -1, 0, 1, 0 }, dy[] = { 0, 1, 0, -1 };

void bfs() {
    queue<maze> q;
    q.push({ sx, sy, 0 });
    while (!q.empty()) {
        //k는 열쇠 값
        int x = q.front().x, y = q.front().y, k = q.front().k; q.pop();
        //1에 도착했으면 return
        if (a[x][y] == '1') {
            printf("%d\n", dist[x][y][k]);
            return;
        }
        //동 서 남 북을 검사한다
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i], ny = y + dy[i], nk = k;
            //예외조건 검사
            if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
            char next = a[nx][ny];
            //nk에 a~f열쇠를 추가
            if ('a' <= next && next <= 'f') nk |= (1 << (next - 'a'));
            //만약 A~F에 해당하는 열쇠를 가지고 있지 않으면 continue
            else if ('A' <= next && next <= 'F') {
                if (!(nk & (1 << (next - 'A')))) continue;
            }
            //이미 방문한 곳이라면 continue
            if (dist[nx][ny][nk] || next == '#') continue;
            q.push({ nx, ny, nk });
            dist[nx][ny][nk] = dist[x][y][k] + 1;
        }
    }
    printf("-1\n");
}

int main() {
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> a[i][j];
            if (a[i][j] == '0') sx = i, sy = j;
        }
    }
    bfs();
    return 0;
}

//https://rebas.kr/738 를 참고함
