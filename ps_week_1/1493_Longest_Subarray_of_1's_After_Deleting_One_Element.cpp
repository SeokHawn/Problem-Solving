class Solution {
public:
	int longestSubarray(vector<int>& nums) {
		int pre = 0, now = 0, res = 0, longest = 0;
		bool zero_f = 0;
		for (int i = 0; i<nums.size(); ++i) {
			if (nums[i]) {
				now++;
				longest = max(longest, now);
			}
			else {
				zero_f = true;
				res = max(res, pre + now);
				pre = now;
				now = 0;
			}
			if (i == nums.size() - 1) {
				if (zero_f) {
					res = max(res, now + pre);
				}
				else {
					res = longest - 1;
				}
			}
		}
		return res;

	}
};