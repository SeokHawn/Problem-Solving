#include <iostream>
#include <string.h>
#include <queue>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;
class Solution {
public:

	int smallestDistancePair(vector<int>& nums, int k) {
		sort(nums.begin(), nums.end());
		int l = 0, r = nums[nums.size() - 1] - nums[0];
		
		while (l<=r) {
			int mid = (l + r) / 2;
			int cnt = 0;
			int j = 0;
			for (int i = 0; i < nums.size()-1; ++i) {
				while (j < nums.size() && nums[j] - nums[i] <= mid) {
					++j;
				}
				cnt += j - i - 1;
			}
			if (cnt < k) {
				l = mid + 1;
			}
			else {
				r = mid - 1;
			}
			
		}

		return l;
	}
};

int main() {

	Solution s;
	vector<int> v = { 1,3,1};
	int res = s.smallestDistancePair(v, 1);
	cout << res;
	return 0;
}