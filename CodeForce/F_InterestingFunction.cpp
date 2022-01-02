#include <string>

using namespace std;

int reverse(string s) {
	int len = s.length();
	int sum = 0, num = 0;
	for(int i=0; i<len; i++) {
		if(s[i] == '0') continue;
		num++;
		string str = "";
		str += s[i];
		for(int j=i+1; j<len; j++) {
			if(j == len - 1) {
				str += s[i] - 1;
				continue;
			}
			str += s[i];
		}
		if(stoi(str) <= 9) str[0]--;
		sum += stoi(str);
	}
	
	return sum + (num - 1);
}

void Solve() {
	int n1, n2;
	scanf("%d%d", &n1, &n2);

	string l = to_string(n1);
	string r = to_string(n2);

	printf("%d\n", reverse(r) - reverse(l));
}

int main() {
	int t;
	scanf("%d", &t);
	while(t--) {
		Solve();
	}
}

/*
3
1 4
1 32
4 32
*/