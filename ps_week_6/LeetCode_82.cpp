#include <iostream>
#include <string.h>
#include <queue>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

 struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
 };

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
		ListNode* tmp = nullptr,*next = nullptr, *res=nullptr;
		if (head == nullptr)
			return head;
		next = head;
		int numtmp=0;
		while (next != nullptr) {
			int cnt = 0;
			numtmp = next->val;
			while (next->val == numtmp && next->next!= nullptr && next->next->val == next->val) {
				next = next->next;
				cnt++;
			}
			if (!cnt) {
				if (tmp == nullptr) {
					res = tmp = next;
				}
				else {
					tmp ->next = next;
					tmp = tmp->next;
				}
				next = next->next;
				tmp->next = nullptr;
			}
			else
				next = next->next;
		}
		return res;
    }
};

int main() {

	Solution s;
	ListNode e4(3);
	ListNode e3(3,&e4);
	ListNode e2(2, &e3);
	ListNode e1(1,&e2);
	ListNode e(1,&e1);
	s.deleteDuplicates(&e);

	return 0;
}