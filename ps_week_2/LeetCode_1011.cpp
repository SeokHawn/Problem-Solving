class Solution {
public:
	static bool cal(int val, vector<int>& nums, int chck) {
		int tmp = 0, cnt = 0;
		for (int i = 0; i<nums.size(); i++) {
			if (tmp + nums[i] <= val) {
				tmp += nums[i];
			}
			else {
				cnt++;
				tmp = 0;
				if (nums[i] <= val) {
					tmp += nums[i];
				}
				else {
					return false;
				}
			}
		}

		if (cnt + 1 <= chck)
			return true;
		return false;

	}
	int shipWithinDays(vector<int>& weights, int D) {
		int sum = 0, res = INT_MAX;
		for (int i : weights) {
			sum += i;
		}
		int l = 0, r = sum;
		while (l < r) {
			int mid = (l + r) / 2;

			if (cal(mid, weights, D)) {
				res = min(res, mid);
				r = mid - 1;
			}
			else {
				l = mid + 1;
			}
		}
		if (cal(l, weights, D)) {
			res = min(res, l);
		}
		return res;
	}
};