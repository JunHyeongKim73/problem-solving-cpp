#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
	int N;
	cin >> N;
	string str;
	int stack[10000];
	int top = -1;
	for (int i = 0; i <= N; i++) {
		getline(cin, str);
		if (i == 0)
			continue;
		if (str == "top") {
			if (top == -1)
				printf("%d \n", -1);
			else
				printf("%d \n", stack[top]);
		}
		else if (str == "pop") {
			if (top == -1)
				printf("%d \n", -1);
			else {
				printf("%d \n", stack[top]);
				top--;
			}
		}
		else if (str == "size") {
			printf("%d \n", top + 1);
		}
		else if (str == "empty") {
			if (top == -1)
				printf("%d \n", 1);
			else
				printf("%d \n", 0);
		}
		else{
			string num;
			for (int j = 5; j < str.length(); j++)
				num.push_back(str[j]);
			top++;
			stack[top] = atoi(num.c_str());
		}
	}
}
