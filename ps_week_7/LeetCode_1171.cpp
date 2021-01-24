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
	 ListNode * removeZeroSumSublists(ListNode* head) {
		
		 ListNode* tmp = nullptr, *now = head;
		 vector< pair <int, ListNode*> > v;
		 v.push_back({ 0,nullptr });
		 while (now != nullptr) {
			 v.push_back({ v[v.size() - 1].first + now->val,now });
				 int l = v[v.size() - 1].first;
				 int cnt = 1;
				 for (int i = v.size()-2; i >=0; i--) {
					 if (l == v[i].first) {
						 while (cnt--) {
							 v.pop_back();
						 }
						 if (v.size() == 1) {
							 head = now->next;
						 }
						 else
							 v[i].second->next = now->next;
						 
					 }
					 else
						 cnt++;
				 }
			 now = now->next;
		 }
		 return head;
	 }
 };
int main() {
	Solution s;
	ListNode e4(-3);
	ListNode e3(-2,&e4);
	ListNode e2(0, &e3);
	ListNode e1(0,&e2);
	ListNode e(1,&e1);
	s.removeZeroSumSublists(&e);
	return 0;
}