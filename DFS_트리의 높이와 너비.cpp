#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int N, order = 1;
vector<pair<int, int>> ans;

typedef struct node {
	int s;
	struct node* left;
	struct node* right;
	struct node* parent;
}Node;

void Inorder(Node* root) {
	if(root->left != NULL) Inorder(root->left);
	root->s = order; order++;
	if(root->right != NULL) Inorder(root->right);
	return;
}

void BFS(Node* root) {
	queue<Node*> q;
	queue<int> dist;
	q.push(root);
	dist.push(1);
	while (!q.empty()) {
		Node* cur = q.front();
		int n = dist.front();
		q.pop(); dist.pop();
		ans.push_back({ n,cur->s });
		if (cur->left != NULL) { q.push(cur->left); dist.push(n + 1); }
		if (cur->right != NULL) { q.push(cur->right); dist.push(n + 1); }
	}
}

int main() {
	cin >> N;
	vector<Node*>node(N + 1);
	for (int i = 1; i <= N; i++) {
		node[i] = new Node;
		node[i]->parent = NULL;
	}
	
	for (int i = 1; i <= N; i++) {
		int num, l_num, r_num;
		cin >> num >> l_num >> r_num;
		node[num]->s = 0;
		if (l_num != -1) { node[num]->left = node[l_num]; node[l_num]->parent = node[num]; }
		else node[num]->left = NULL;
		if (r_num != -1) { node[num]->right = node[r_num]; node[r_num]->parent = node[num]; }
		else node[num]->right = NULL;
	}
	//root 구하기
	Node* root = node[1];
	while (root->parent != NULL) root = root->parent;

	//중위 순회
	Inorder(root);

	//모든 level을 검사
	BFS(root);
	int max_level = 1, max_width = 1;
	int prev_level = 0, prev_width = 0, width = 0;
	for (int i = 0; i < N; i++) {
		if (prev_level != ans[i].first) { 
			prev_level = ans[i].first;
			prev_width = ans[i].second;
			width = 0;
			continue;
		}
		width += ans[i].second - prev_width;
		if (width + 1 > max_width) {
			max_width = width + 1;
			max_level = prev_level;
		}
		prev_level = ans[i].first;
		prev_width = ans[i].second;
	}

	printf("%d %d \n", max_level, max_width);
}
/*
5
3 1 2
1 4 -1
2 -1 5
4 -1 -1
5 -1 -1

13
1 2 3
2 4 5
3 6 7
4 -1 -1
5 8 -1
6 -1 -1
7 -1 9
8 10 -1
9 -1 11
10 12 -1
11 -1 13
12 -1 -1
13 -1 -1

19
1 2 3
2 4 5
3 6 7
4 8 -1
5 9 10
6 11 12
7 13 -1
8 -1 -1
9 14 15
10 -1 -1
11 16 -1
12 -1 -1
13 17 -1
14 -1 -1
15 18 -1
16 -1 -1
17 -1 19
18 -1 -1
19 -1 -1
*/
