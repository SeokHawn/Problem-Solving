#include <iostream>
#include <string.h>
#include <queue>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;
class Solution {
public:
	vector<int> rearrangeBarcodes(vector<int>& barcodes) {
		map<int, int > m;
		for (int i = 0; i < barcodes.size(); i++) {
			m[barcodes[i]]++;
		}
		priority_queue< pair < int, int >> pq;

		vector<int> res;

		for (pair<int, int> i : m) {
			pq.push({ i.second, i.first});
		}
		pair<int, int > many;
		if (!pq.empty()) {
			many = pq.top();
			pq.pop();
			res.push_back(many.second);
			many.first--;
		}
		while (!pq.empty()) {
			pair<int, int > tmp = pq.top();
			pq.pop();
			res.push_back(tmp.second);
			tmp.first--;
			if (many.first) {
				pq.push(many);
			}
			many = tmp;
		}
		return res;
	}
};

int main() {
	
	Solution s;
	vector<int> v = { 1,1,1,2,3, };
	v = s.rearrangeBarcodes(v);

	return 0;
}