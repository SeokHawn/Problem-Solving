#include <iostream>
#include <string.h>
#include <queue>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;


class Solution {
public:
	int rest[41][41];
	bool isrange(int x, int y, int N, int M) {
		return x >= 0 && y >= 0 && x < N && y < M;
	}
	int dir_x[4] = { 0,0,1,-1 },
		dir_y[4] = { 1,-1,0,0 };
	struct node {
		int r, c, cnt,k;
		node(int x, int y, int v, int l) {
			r = y;
			c = x;
			cnt = v;
			k = l;
		}
	};

	int shortestPath(vector<vector<int>>& grid, int k) {
		int res = -1;
		if (grid[0][0])
			return res;
		queue<node> q;
		q.push(node(0, 0, 0, k));
		int M = grid.size(), N = grid[0].size();
		for (int i = 0; i < M; ++i) {
			for (int j = 0; j < N; ++j) {
				rest[i][j] = -1;
			}
		}
		while (!q.empty()) {
			node tmp = q.front();
			q.pop();
			if (tmp.r == M - 1 && tmp.c == N - 1) {
				res = tmp.cnt;
				break;
			}
			for (int i = 0; i < 4; i++) {
				int nx = tmp.c + dir_x[i],
					ny = tmp.r + dir_y[i];
				if (isrange(nx, ny, N, M) ) {
					if (grid[ny][nx] && rest[ny][nx] < tmp.k - 1 ) {
						rest[ny][nx] = tmp.k - 1;
						q.push(node(nx, ny, tmp.cnt + 1, tmp.k - 1));
					}
					if(!grid[ny][nx] && rest[ny][nx] < tmp.k){
						rest[ny][nx] = tmp.k ;
						q.push(node(nx, ny, tmp.cnt + 1, tmp.k));
					}
				}
			}

		}
		return res;
	}
};
int main() {
	Solution s;
	vector<vector<int> > g;

	g = { {0, 0},
{1, 0},{1, 0},{1, 0},{1, 0},{1, 0},{0, 0},{0, 1},{0, 1},{0, 1},{0, 0},{1, 0},{1, 0},{0, 0} };
	cout << s.shortestPath(g, 4);
	return 0;
}