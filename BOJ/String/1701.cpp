#include <iostream>
#include <string>

using namespace std;

// Fills lps[] for given patttern pat[0..M-1]
void computeLPSArray(string& pat, int M, int* lps) {
	// length of the previous longest prefix suffix
	int len = 0;

	lps[0] = 0; // lps[0] is always 0

	// the loop calculates lps[i] for i = 1 to M-1
	int i = 1;
	while (i < M) {
		if (pat[i] == pat[len]) {
			len++;
			lps[i] = len;
			i++;
		}
		else // (pat[i] != pat[len])
		{
			// This is tricky. Consider the example.
			// AAACAAAA and i = 7. The idea is similar
			// to search step.
			if (len != 0) {
				len = lps[len - 1];

				// Also, note that we do not increment
				// i here
			}
			else // if (len == 0)
			{
				lps[i] = 0;
				i++;
			}
		}
	}
}

bool KMPSearch(string& pat, string& txt, int start) {
	int N = txt.length();
	int M = pat.length();

	// 매칭하려는 문자열의 길이가 더 길면 문자열을 탐색할 수 없다
	if(N - start < M) return false;

	// create lps[] that will hold the longest prefix suffix
	// values for pattern
	int lps[M];

	// Preprocess the pattern (calculate lps[] array)
	computeLPSArray(pat, M, lps);

	int i = start; // index for txt[]
	int j = 0; // index for pat[]
	while (i < N) {
		if (pat[j] == txt[i]) {
			j++;
			i++;
		}

		if (j == M) {
			return true;
			j = lps[j - 1];
		}

		// mismatch after j matches
		else if (i < N && pat[j] != txt[i]) {
			// Do not match lps[0..lps[j-1]] characters,
			// they will match anyway
			if (j != 0)
				j = lps[j - 1];
			else
				i = i + 1;
		}
	}

	return false;
}

int main() {
	ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

	string txt;
	cin>>txt;
	
	// 문자열의 길이를 N, 지금까지 나온 부분문자열 중 가장 긴 문자열의 길이를 M이라고 하자.
	// 인덱스 i에서 시작하는 길이가 (M+1)인 문자열을 패턴으로 인덱스 (i+1)...(N-1)인 문자열을 텍스트로 설정하여 KMP search를 진행한다
	// 텍스트에서 매칭되는 문자열을 찾으면 패턴을 인덱스 i에서 시작하는 길이가 (M+2)인 문자열로 두고 진행한다
	// 찾지 못한다면 인덱스를 1 증가시켜 패턴이 매칭되는지 확인한다
	int N = txt.length();
	int M = 0;
	for(int i=0; i<N; i++) {
		// 가장 긴 길이를 초과하는 문자열을 찾을 수 없으면 루프를 멈춘다
		if(M >= N - i - 1) break;
		
		// 문자열을 쌓아가면서 KMP 탐색을 한다
		string pat = "";
		for(int j=0; j<N-1; j++) {
			pat += txt[i+j];
			// M 이하의 패턴은 KMP search를 진행하지 않는다
			if(M >= j + 1) continue;
			
			// 패턴이 매칭되지 않는다면 인덱스를 증가시킨다
			if(!KMPSearch(pat, txt, i+1)) break;
			M = j + 1;
		}
	}

	cout<<M<<endl;
}