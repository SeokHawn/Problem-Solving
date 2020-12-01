class Solution {
public:
	int cal(int x, int y, int x2, int y2) {
		return abs(x - x2) + y + y2;
	}
	int findMaxValueOfEquation(vector<vector<int>>& points, int k) {
		int res = INT_MIN;
		priority_queue<pair<int, int>> pq;

		for (int i = 0; i<points.size(); ++i) {

			while (!pq.empty() && (points[i][0] - pq.top().second) > k) {
				pq.pop();
			}

			if (!pq.empty()) {
				res = max(res, pq.top().first + points[i][0] + points[i][1]);
			}
			pq.push({ points[i][1] - points[i][0], points[i][0] });
		}

		return res;
	}
};
