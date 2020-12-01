class Solution {
public:
	struct info {
		int s, e, w;
		info() {
			s = e = w = 0;
		}
		info(int a, int b, int c) {
			s = a;
			e = b;
			w = c;
		}
	};
	static bool compare(const info& a, const info& b) {
		return a.s < b.s;
	}
	int bin_search(int l, int r, int val, const info *list) {
		int mid = 0, res = 0;
		while (l <= r) {
			mid = (l + r) / 2;
			if (list[mid].s >= val) {
				res = mid;
				r = mid - 1;
			}
			else {
				l = mid + 1;
			}
		}
		return res;
	}
	int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {

		int *dp = new int[startTime.size()];
		int N = startTime.size(), res = 0;
		info *list = new info[startTime.size()];
		for (int i = 0; i < startTime.size(); ++i) {
			list[i].s = startTime[i];
			list[i].e = endTime[i];
			list[i].w = profit[i];
		}

		sort(list, list + startTime.size(), compare);
		memset(dp, 0, sizeof(dp));
		dp[N - 1] = list[N - 1].w;
		for (int i = N - 2; i >= 0; i--) {
			int index = bin_search(0, N - 1, list[i].e, list);
			dp[i] = max(dp[i + 1], dp[index] + list[i].w);
		}
		res = max(dp[0], dp[1]);

		return res;
	}

};