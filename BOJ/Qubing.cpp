#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>
using namespace std;

#define w 'w'
#define y 'y'
#define r 'r'
#define o 'o'
#define g 'g'
#define b 'b'

int main() {
	int T;
	cin >> T;
	while (T--) {
		char U[3][3] = { w,w,w,w,w,w,w,w,w };
		char D[3][3] = { y,y,y,y,y,y,y,y,y };
		char F[3][3] = { r,r,r,r,r,r,r,r,r };
		char B[3][3] = { o,o,o,o,o,o,o,o,o };
		char L[3][3] = { g,g,g,g,g,g,g,g,g };
		char R[3][3] = { b,b,b,b,b,b,b,b,b };
		int n;
		cin >> n;
		vector<string> vs(n);
		for (int i = 0; i < n; i++)
			cin >> vs[i];

		for (int i = 0; i < n; i++) {
			char c = vs[i][0], d = vs[i][1];
			//자기 면도 뒤집히는 거 생각!!!
			if ((c == 'U' && d == '+') || (c == 'D' && d == '-')) {
				int j;
				if (c == 'U') j = 0;
				if (c == 'D') j = 2;
				char c1 = L[j][0], c2 = L[j][1], c3 = L[j][2];
				L[j][0] = F[j][0], L[j][1] = F[j][1], L[j][2] = F[j][2];
				F[j][0] = R[j][0], F[j][1] = R[j][1], F[j][2] = R[j][2];
				R[j][0] = B[j][0], R[j][1] = B[j][1], R[j][2] = B[j][2];
				B[j][0] = c1, B[j][1] = c2, B[j][2] = c3;
				if (c == 'U') {
					char c11 = U[0][0], c12 = U[0][1];
					U[0][0] = U[2][0], U[2][0] = U[2][2], U[2][2] = U[0][2], U[0][2] = c11;
					U[0][1] = U[1][0], U[1][0] = U[2][1], U[2][1] = U[1][2], U[1][2] = c12;
				}
				if (c == 'D') {
					char c11 = D[0][0], c12 = D[0][1];
					D[0][0] = D[0][2], D[0][2] = D[2][2], D[2][2] = D[2][0], D[2][0] = c11;
					D[0][1] = D[1][2], D[1][2] = D[2][1], D[2][1] = D[1][0], D[1][0] = c12;
				}
			}
			else if ((c == 'U' && d == '-') || (c == 'D' && d == '+')) {
				int j;
				if (c == 'U') j = 0;
				if (c == 'D') j = 2;
				char c1 = L[j][0], c2 = L[j][1], c3 = L[j][2];
				L[j][0] = B[j][0], L[j][1] = B[j][1], L[j][2] = B[j][2];
				B[j][0] = R[j][0], B[j][1] = R[j][1], B[j][2] = R[j][2];
				R[j][0] = F[j][0], R[j][1] = F[j][1], R[j][2] = F[j][2];
				F[j][0] = c1, F[j][1] = c2, F[j][2] = c3;
				if (c == 'D') {
					char c11 = D[0][0], c12 = D[0][1];
					D[0][0] = D[2][0], D[2][0] = D[2][2], D[2][2] = D[0][2], D[0][2] = c11;
					D[0][1] = D[1][0], D[1][0] = D[2][1], D[2][1] = D[1][2], D[1][2] = c12;
				}
				if (c == 'U') {
					char c11 = U[0][0], c12 = U[0][1];
					U[0][0] = U[0][2], U[0][2] = U[2][2], U[2][2] = U[2][0], U[2][0] = c11;
					U[0][1] = U[1][2], U[1][2] = U[2][1], U[2][1] = U[1][0], U[1][0] = c12;
				}
			}
			else if ((c == 'R' && d == '+') || (c == 'L' && d == '-')) {
				int j, k;
				if (c == 'R') { j = 2, k = 0; }
				if (c == 'L') { j = 0, k = 2; }
				char c1 = U[0][j], c2 = U[1][j], c3 = U[2][j];
				U[0][j] = F[0][j], U[1][j] = F[1][j], U[2][j] = F[2][j];
				F[0][j] = D[0][j], F[1][j] = D[1][j], F[2][j] = D[2][j];
				D[0][j] = B[2][k], D[1][j] = B[1][k], D[2][j] = B[0][k];
				B[2][k] = c1, B[1][k] = c2, B[0][k] = c3;
				if (c == 'R') {
					char c11 = R[0][0], c12 = R[0][1];
					R[0][0] = R[2][0], R[2][0] = R[2][2], R[2][2] = R[0][2], R[0][2] = c11;
					R[0][1] = R[1][0], R[1][0] = R[2][1], R[2][1] = R[1][2], R[1][2] = c12;
				}
				if (c == 'L') {
					char c11 = L[0][0], c12 = L[0][1];
					L[0][0] = L[0][2], L[0][2] = L[2][2], L[2][2] = L[2][0], L[2][0] = c11;
					L[0][1] = L[1][2], L[1][2] = L[2][1], L[2][1] = L[1][0], L[1][0] = c12;
				}
			}
			else if ((c == 'R' && d == '-') || (c == 'L' && d == '+')) {
				int j, k;
				if (c == 'R') { j = 2, k = 0; }
				if (c == 'L') { j = 0, k = 2; }
				char c1 = U[0][j], c2 = U[1][j], c3 = U[2][j];
				U[0][j] = B[2][k], U[1][j] = B[1][k], U[2][j] = B[0][k];
				B[2][k] = D[0][j], B[1][k] = D[1][j], B[0][k] = D[2][j];
				D[0][j] = F[0][j], D[1][j] = F[1][j], D[2][j] = F[2][j];
				F[0][j] = c1, F[1][j] = c2, F[2][j] = c3;
				if (c == 'L') {
					char c11 = L[0][0], c12 = L[0][1];
					L[0][0] = L[2][0], L[2][0] = L[2][2], L[2][2] = L[0][2], L[0][2] = c11;
					L[0][1] = L[1][0], L[1][0] = L[2][1], L[2][1] = L[1][2], L[1][2] = c12;
				}
				if (c == 'R') {
					char c11 = R[0][0], c12 = R[0][1];
					R[0][0] = R[0][2], R[0][2] = R[2][2], R[2][2] = R[2][0], R[2][0] = c11;
					R[0][1] = R[1][2], R[1][2] = R[2][1], R[2][1] = R[1][0], R[1][0] = c12;
				}
			}
			else if ((c == 'F' && d == '+') || (c == 'B' && d == '-')) {
				int j, k;
				if (c == 'F') { j = 2, k = 0; }
				if (c == 'B') { j = 0, k = 2; }
				char c1 = U[j][2], c2 = U[j][1], c3 = U[j][0];
				U[j][2] = L[0][j], U[j][1] = L[1][j], U[j][0] = L[2][j];
				L[0][j] = D[k][0], L[1][j] = D[k][1], L[2][j] = D[k][2];
				D[k][0] = R[2][k], D[k][1] = R[1][k], D[k][2] = R[0][k];
				R[2][k] = c1, R[1][k] = c2, R[0][k] = c3;
				if (c == 'F') {
					char c11 = F[0][0], c12 = F[0][1];
					F[0][0] = F[2][0], F[2][0] = F[2][2], F[2][2] = F[0][2], F[0][2] = c11;
					F[0][1] = F[1][0], F[1][0] = F[2][1], F[2][1] = F[1][2], F[1][2] = c12;
				}
				if (c == 'B') {
					char c11 = B[0][0], c12 = B[0][1];
					B[0][0] = B[0][2], B[0][2] = B[2][2], B[2][2] = B[2][0], B[2][0] = c11;
					B[0][1] = B[1][2], B[1][2] = B[2][1], B[2][1] = B[1][0], B[1][0] = c12;
				}
			}
			else if ((c == 'F' && d == '-') || (c == 'B' && d == '+')) {
				int j, k;
				if (c == 'F') { j = 2, k = 0; }
				if (c == 'B') { j = 0, k = 2; }
				char c1 = U[j][2], c2 = U[j][1], c3 = U[j][0];
				U[j][2] = R[2][k], U[j][1] = R[1][k], U[j][0] = R[0][k];
				R[2][k] = D[k][0], R[1][k] = D[k][1], R[0][k] = D[k][2];
				D[k][0] = L[0][j], D[k][1] = L[1][j], D[k][2] = L[2][j];
				L[0][j] = c1, L[1][j] = c2, L[2][j] = c3;
				if (c == 'B') {
					char c11 = B[0][0], c12 = B[0][1];
					B[0][0] = B[2][0], B[2][0] = B[2][2], B[2][2] = B[0][2], B[0][2] = c11;
					B[0][1] = B[1][0], B[1][0] = B[2][1], B[2][1] = B[1][2], B[1][2] = c12;
				}
				if (c == 'F') {
					char c11 = F[0][0], c12 = F[0][1];
					F[0][0] = F[0][2], F[0][2] = F[2][2], F[2][2] = F[2][0], F[2][0] = c11;
					F[0][1] = F[1][2], F[1][2] = F[2][1], F[2][1] = F[1][0], F[1][0] = c12;
				}
			}
			/*printf("윗면 \n");
			for (int i = 0; i < 3; i++) {
				for (int j = 0; j < 3; j++)
					printf("%c", U[i][j]);
				printf("\n");
			}
			printf("\n");
			printf("아랫면 \n");
			for (int i = 0; i < 3; i++) {
				for (int j = 0; j < 3; j++)
					printf("%c", D[i][j]);
				printf("\n");
			}
			printf("\n");
			printf("앞면 \n");
			for (int i = 0; i < 3; i++) {
				for (int j = 0; j < 3; j++)
					printf("%c", F[i][j]);
				printf("\n");
			}
			printf("\n");
			printf("뒷면 \n");
			for (int i = 0; i < 3; i++) {
				for (int j = 0; j < 3; j++)
					printf("%c", B[i][j]);
				printf("\n");
			}
			printf("\n");
			printf("왼옆면 \n");
			for (int i = 0; i < 3; i++) {
				for (int j = 0; j < 3; j++)
					printf("%c", L[i][j]);
				printf("\n");
			}
			printf("\n");
			printf("오옆면 \n");
			for (int i = 0; i < 3; i++) {
				for (int j = 0; j < 3; j++)
					printf("%c", R[i][j]);
				printf("\n");
			}
			printf("\n");*/
			
		}
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++)
				printf("%c", U[i][j]);
			printf("\n");
		}
		vs.clear();
	}
}
/*
4
1
L-
2
F+ B+
4
U- D- L+ R+
10
L- U- L+ U- L- U- U- L+ U+ U+

1
24
L+ U+ D- B+ B+ U+ D- U+ D- F+ U- U- F- U+ D- U+ D- B+ B+ U- D+ L- U+ U+
*/
