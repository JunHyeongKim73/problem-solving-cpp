#include <iostream>
#include <vector>
#include <string>
#include <stack>
using namespace std;

int main() {
	int N;
	cin >> N;
	for (int i = 0; i < N; i++) {
		string str;
		bool flag = false;
		stack<char> s;
		cin >> str;
		for (int j = 0; j < str.length(); j++) {
			if (str[j] == '(')
				s.push(str[i]);
			else {
				if (s.empty()) {
					printf("NO \n");
					flag = true;
					break;
				}
				s.pop();
			}
		}
		if (flag)
			continue;
		if (s.empty())
			printf("YES \n");
		else
			printf("NO \n");
	}
}
