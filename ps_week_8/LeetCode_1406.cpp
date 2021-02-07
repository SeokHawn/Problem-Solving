#include <iostream>
#include <string.h>
#include <queue>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;
class Solution {
public:
	int MAX_V = 987654321;
	vector<int> dp;
	string stoneGameIII(vector<int>& stoneValue) {
		int N = stoneValue.size();
		vector<int> dp(N + 1, -MAX_V);
		dp[N] = 0;

		for (int i = N - 1; i >= 0; i--) {
			int s = 0;
			for (int j = i, limit = min(N, i + 3); j < limit; j++) {
				s += stoneValue[j];
				dp[i] = max(dp[i], s - dp[j + 1]);
			}
		}
		if (dp[0] > 0) {
			return "Alice";
		}
		else if (dp[0] == 0) {
			return "Tie";
		}
		else
			return "Bob";
	}
};
int main() {
	Solution s;
	vector<int> v = {1,2,3};
	s.stoneGameIII(v);
	return 0;
}