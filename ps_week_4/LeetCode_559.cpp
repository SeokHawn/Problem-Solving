/*
// Definition for a Node.
class Node {
public:
int val;
vector<Node*> children;

Node() {}

Node(int _val) {
val = _val;
}

Node(int _val, vector<Node*> _children) {
val = _val;
children = _children;
}
};
*/

class Solution {
public:
	int maxres = 0;
	int dfs(Node* root, int cnt) {
		for (int i = 0; i < root->children.size(); ++i) {
			maxres = max(maxres, dfs(root->children[i], cnt + 1));
		}
		return max(maxres, cnt);
	}

	int maxDepth(Node* root) {
		if (root == NULL)
			return 0;
		else
			return dfs(root, 1);
	}
};