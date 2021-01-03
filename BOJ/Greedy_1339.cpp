#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>

using namespace std;

int main(){
	int N;
	cin>>N;
	vector<int> v(26);
	for(int i=0; i<N; i++){
		string s;
		cin>>s;
		int len = s.length();
		for(int j=0; j<len; j++){
			v[s[j]-65] += pow(10, len-j-1);
		}
	}
	sort(v.begin(), v.end(), greater<>());
	
	int result = 0;
	for(int i=0; i<26; i++){
		if(v[i] == 0) break;
		result += v[i] * (9 - i);
	}
	
	printf("%d \n", result);
	/*
	순서대로 정리해서 9~~1까지 넣어주면 됨.
	*/
}