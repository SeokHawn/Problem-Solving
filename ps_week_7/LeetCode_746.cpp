#include <iostream>
#include <string.h>
#include <queue>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

class Solution {
public:
	int MAX = 987654321;
	int dp[1002];
	int minCostClimbingStairs(vector<int>& cost) {
		cost.push_back(0);
		for (int i = 0; i < cost.size(); ++i)
			dp[i] = MAX;
		dp[0] = cost[0];
		dp[1] = cost[1];
		for (int i = 2; i < cost.size(); ++i) {
			dp[i] = cost[i] + min(dp[i - 1], dp[i - 2]);
		}
		return dp[cost.size()-1];
	}
}; 
int main() {
	Solution s;
	vector<int> v = { 0,0,1,1 };
	s.minCostClimbingStairs(v);
	return 0;
}