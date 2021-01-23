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
	 ListNode * oddEvenList(ListNode* head) {
		 ListNode* odd = head,*second = nullptr, *even = nullptr;
		 if (head->next != nullptr)
			 second = even = head->next;
		 else
			 return head;

		 while (1) {
			 if (even->next!= nullptr) {
				 odd->next = even->next;
				 odd = odd->next;
				 if (odd->next != nullptr) {
					 even->next = odd->next;
					 even = even->next;
				 }
				 else {
					 odd->next = second;
					 even->next = nullptr;
					 break;
				 }
			 }
			 else {
				 odd->next = second;
				 break;
			 }
		 }
		 return head;
	 }
 };
int main() {
	Solution s;
	ListNode e4(5);
	ListNode e3(4,&e4);
	ListNode e2(3, &e3);
	ListNode e1(2,&e2);
	ListNode e(1,&e1);
	s.oddEvenList(&e);
	return 0;
}