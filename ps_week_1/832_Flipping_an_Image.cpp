class Solution {
public:
	vector<vector<int>> flipAndInvertImage(vector<vector<int>>& A) {
		for (int i = 0; i<A.size(); ++i) {
			vector<int> tmp;
			for (int j = A[i].size() - 1; j >= 0; j--) {
				tmp.push_back(A[i][j]);
				if (!j)
					A[i] = tmp;
			}
			for (int j = 0; j<A[i].size(); ++j) {
				A[i][j] = !A[i][j];
			}
		}
		return A;
	}
};