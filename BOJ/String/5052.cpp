#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>

using namespace std;

const int ALPAHBET_SIZE = 10;

typedef struct trieNode {
	struct trieNode* children[ALPAHBET_SIZE];
	bool isEndOfWord;
} TrieNode;

TrieNode* newNode() {
	TrieNode* pNode = new TrieNode;
	
	pNode -> isEndOfWord = false;
	for(int i=0; i<ALPAHBET_SIZE; i++){
		pNode->children[i] = NULL;
	}

	return pNode;
}

void insert(TrieNode* root, string key) {
	TrieNode* pCrawl = root;

	int len = key.length();
	for(int i=0; i<len; i++) {
		int index = key[i] - '0';
		if(pCrawl->children[index] == NULL) {
			pCrawl->children[index] = newNode();
		}

		pCrawl = pCrawl->children[index];
	}

	pCrawl->isEndOfWord = true;
}

bool hasConsistency(TrieNode* root, string key) {
	TrieNode* pCrawl = root;

	int len = key.length();
	for(int i=0; i<len; i++) {
		int index = key[i] - '0';
		if(pCrawl->isEndOfWord) return false;
		pCrawl = pCrawl->children[index];
	}

	return true;
}

int main() {
	ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

	int t;
	cin>>t;
	while(t--) {
		int n;
		cin>>n;

		vector<string> arr(n);
		for(int i=0; i<n; i++){
			cin>>arr[i];
		}

		// 트라이에 모든 전화번호를 집어넣는다
		TrieNode* root = newNode();

		for(int i=0; i<n; i++) {
			insert(root, arr[i]);
		}

		// 트라이에서 각각의 전화번호를 탐색하면서
		// 일관성 여부를 확인한다
		int i;
		for(i=0; i<n; i++) {
			if(!hasConsistency(root, arr[i])) break;
		}

		if(i == n) {
			cout<<"YES\n";
		}
		else {
			cout<<"NO\n";
		}
	}
}

/*
https://www.geeksforgeeks.org/trie-insert-and-search/
*/