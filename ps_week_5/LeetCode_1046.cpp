#include <iostream>
#include <string.h>
#include <queue>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;


class Solution {
public:
	int lastStoneWeight(vector<int>& stones) {
		while (stones.size()>1) {
			sort(stones.begin(), stones.end());
			int y = stones[stones.size() - 1],
				x = stones[stones.size() - 2];
			if (x == y) {
				stones.erase(stones.end()-1);
				stones.erase(stones.end()-1);
			}
			else {
				int adder = y - x;
				stones.erase(stones.end()-1);
				stones.erase(stones.end()-1);
				stones.push_back(adder);
			}
		}
		if (stones.size()) {
			return stones[0];
		}
		else
			return 0;
	}
}; 
