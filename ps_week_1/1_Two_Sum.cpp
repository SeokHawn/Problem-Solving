class Solution {
public:
	vector<int> twoSum(vector<int>& nums, int target) {
		int first = -1, second = -1;
		vector<int> v;
		for (int i = 0; i < nums.size() - 1; i++) {
			first = i;
			for (int j = i + 1; j < nums.size(); j++) {
				if (nums[first] + nums[j] == target) {
					v.push_back(first);
					v.push_back(j);
					break;
				}
			}
			if (!v.empty())
				break;
		}
		return v;
	}
};