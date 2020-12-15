class Solution {
public:
	bool ischck[101][101];
	bool isrange(int x, int y, int N) {
		return x >= 0 && y >= 0 && x < N && y < N;
	}
	int dir_x[8] = { 0, 0,1,-1, 1,1,-1,-1 },
		dir_y[8] = { 1,-1,0,0,1,-1,-1,1 };
	struct node {
		int r, c, cnt;
		node(int x, int y, int v) {
			r = y;
			c = x;
			cnt = v;
		}
	};

	int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
		int res = -1;
		if (grid[0][0] == 1)
			return -1;
		queue<node> q;
		memset(ischck, 0, sizeof(ischck));
		q.push(node(0, 0, 1));
		ischck[0][0] = true;
		while (!q.empty()) {
			node tmp = q.front();
			if (tmp.r == grid.size() - 1 && tmp.c == grid.size() - 1) {
				res = tmp.cnt;
				break;
			}
			q.pop();

			for (int i = 0; i < 8; i++) {
				int nx = tmp.c + dir_x[i],
					ny = tmp.r + dir_y[i];
				if (isrange(nx, ny, grid.size()) && !ischck[ny][nx] && !grid[ny][nx]) {
					ischck[ny][nx] = true;
					q.push(node(nx, ny, tmp.cnt + 1));
				}
			}
		}
		return res;
	}
};