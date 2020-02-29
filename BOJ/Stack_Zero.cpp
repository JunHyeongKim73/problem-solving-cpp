#include <iostream>
#include <vector>
#include <string>
#include <stack>
using namespace std;

int main() {
	int N;
	cin >> N;
	stack<int> s;
	int sum = 0;
	for (int i = 0; i < N; i++) {
		int n;
		cin >> n;
		if (n == 0) {
			sum -= s.top();
			s.pop();
		}
		else {
			s.push(n);
			sum += n;
		}
	}
	printf("%d \n", sum);
}
