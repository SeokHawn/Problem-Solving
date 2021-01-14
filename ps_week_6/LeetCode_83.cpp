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
	 ListNode * deleteDuplicates(ListNode* head) {
		 if (head == nullptr)
			 return head;
		 ListNode *r = nullptr, *l = head;
		 if (l->next != nullptr)
			 r = head->next;
		 while (r != nullptr) {
			 while (r != nullptr && l->val == r->val) {
				 r = r->next;
			 }
			 if (r != nullptr) {
				 l->next = r;
				 l = r;
				 r = l->next;
			 }
			 else
				 break;
		 }
		 l->next = nullptr;
		 return head;
	 }
 };

int main() {

	Solution s;
	ListNode e4(3);
	ListNode e3(3,&e4);
	ListNode e2(2, &e3);
	ListNode e1(1,&e2);
	ListNode e(1,&e1);
	s.deleteDuplicates(nullptr);

	return 0;
}