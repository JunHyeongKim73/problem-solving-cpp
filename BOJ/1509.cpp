#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>

using namespace std;

int cache[2501][2501];
int dp[2501];
string str;
// 문자열의 start ~ (end - 1) Palindrome Check 
int isPalindrome(int start, int end){
	int& ret = cache[start][end];
	if(ret != -1) return ret;
	
	int len = (end - start) / 2;
	for(int i=0; i<len; i++){
		if(str[start + i] != str[end - 1 - i])
			return ret = 0;
	}
	return ret = 1;
}
// Palindrome의 집합으로 문자열을 표현하고 그 개수의 최솟값을 구한다.
int solve(int start){
	int len = str.length();
	int& ret = dp[start];
	if(ret != -1) return ret;
	if(start == len) return ret = 0;
	
	int mins = 10000;
	for(int i=start + 1; i<=len; i++)
		if(isPalindrome(start, i)){
			mins = min(mins, solve(i) + 1);
		}
	return ret = mins;
}

int main(){
	char s[2501];
	scanf("%s", s);
	str = s;
	
	memset(cache, -1, sizeof(cache));
	memset(dp, -1, sizeof(dp));
	int mins = solve(0);
	
	printf("%d \n", mins);
}