#include <iostream>
#include <string>
#include <stack>
#include <vector>

using namespace std;

int main() {
	ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

	string str, exp;
	
	cin>>str;
	cin>>exp;
	
	stack<char> s;

	int strlen = str.length();
	int explen = exp.length();

	for(int i=0; i<strlen; i++) {
		// 폭발 문자열의 마지막 문자와 같은지 비교한다
		if(str[i] == exp[explen-1]) {
			stack<char> tempStack;
			int j;
			for(j=1; j<explen; j++) {
				// 스택이 비어있을 경우 멈춘다
				if(s.empty()) break;

				char c = s.top();
				s.pop();
				tempStack.push(c);
				// 스택에서 꺼낸 숫자와 폭발 문자열의 숫자와 비교한다
				if(c != exp[explen - 1 - j]) break;
			}
			// 스택에서 꺼낸 문자 중 폭발 문자열과 다른 문자가 있다면
			if(j != explen){
				while(!tempStack.empty()){
					char c = tempStack.top();
					tempStack.pop();
					s.push(c);
				}
				// 마지막 문자도 넣는다
				s.push(str[i]);
			}

			continue;
		}

		s.push(str[i]);
	}

	vector<char> v;
	while(!s.empty()){
		char temp = s.top();
		s.pop();

		v.push_back(temp);
	}

	int veclen = v.size();
	string result;

	for(int i=veclen-1; i>=0; i--){
		result += v[i];
	}

	if(result == "") {
		cout<<"FRULA\n";
	}
	else{
		cout<<result<<"\n";
	}
}
