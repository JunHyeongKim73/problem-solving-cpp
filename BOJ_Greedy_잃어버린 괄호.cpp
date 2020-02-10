#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
	string s;
	cin >> s;
	string num;
	int sum = 0, pos = 0;
	bool flag = false;
	for (int i = 0; i < s.length(); i++) {
		if (s[i] == '+' || s[i] == '-') {
			sum = atoi(num.c_str());
			num.clear();
			pos = i + 1;
			if (s[i] == '-')
				flag = true;
			break;
		}
		num.push_back(s[i]);
	}
	num.clear();
	for (int i = pos; i < s.length(); i++) {
		if (s[i] == '+' || s[i] == '-') {
			if (flag)
				sum -= atoi(num.c_str());
			else
				sum += atoi(num.c_str());
			if (s[i] == '-' && !flag)
				flag = true;
			num.clear();
		}
		else {
			num.push_back(s[i]);
		}
	}
	if (flag)
		sum -= atoi(num.c_str());
	else
		sum += atoi(num.c_str());
	printf("%d \n", sum);
}
/*
55-50+40
10+30-20+30-20
*/
