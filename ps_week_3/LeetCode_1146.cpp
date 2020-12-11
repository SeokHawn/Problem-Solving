#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

class SnapshotArray {
public:
	vector<vector<pair< int, int> > > arr;
	int snap_id = 0;
	int l = 0;
	SnapshotArray(int length) {
		l = length;
		vector<pair< int, int > > v;
		v.push_back({ 0,0 });
		for (int i = 0; i < length; ++i)
			arr.push_back(v);
	}

	void set(int index, int val) {
		if (snap_id != arr[index].back().second)
			arr[index].push_back({ val, snap_id });
		else
			arr[index].back().first = val;
	}

	int snap() {
		snap_id++;
		return snap_id - 1;
	}

	int get(int index, int snap_id) {
		int s = 0, e = arr[index].size() - 1, res = 0;
		while (s <= e) {
			int mid = (s + e) / 2;
			if (arr[index][mid].second == snap_id) {
				return arr[index][mid].first;
			}
			if (arr[index][mid].second > snap_id) {
				e = mid - 1;
				if (mid - 1 >= 0)
					res = mid - 1;
			}
			else {
				res = mid;
				s = mid + 1;
			}
		}
		return arr[index][res].first;
	}
};
int main(){

	SnapshotArray s(3);
	s.set(1, 6);
	s.snap();
	s.snap();
	s.set(1, 19);
	s.set(0, 4);
	s.get(2, 0);
	s.get(2, 1); 
	s.get(0, 1);
	
	return 0;
}