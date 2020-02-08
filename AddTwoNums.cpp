///**
// * Definition for singly-linked list.
// * struct ListNode {
// *     int val;
// *     ListNode *next;
// *     ListNode(int x) : val(x), next(NULL) {}
// * };
// */
//
//#include <iostream>
//
//using namespace std;
//
//struct ListNode {
//	int val;
//	ListNode *next;
//	ListNode(int x) : val(x), next(NULL) {}
//	
//};
//
//class Solution {
//public:
//	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
//		int extern_data = 0;
//		ListNode* head = NULL;
//		ListNode* tail = NULL;
//		int val = 0;
//		while (l1 != NULL && l2 != NULL) {
//			val = l1->val + l2->val + extern_data;
//			extern_data = val / 10;
//			insert_data(head, tail, val % 10);
//			l1 = l1->next;
//			l2 = l2->next;
//		}
//		while (l1 != NULL) {
//			if (extern_data != 0) {
//				l1->val += extern_data;
//				extern_data = l1->val / 10;
//				l1->val %= 10;
//			}
//			insert_data(head, tail, l1->val);
//			l1 = l1->next;
//		}
//		while (l2 != NULL) {
//			if (extern_data != 0) {
//				l2->val += extern_data;
//				extern_data = l2->val / 10;
//				l2->val %= 10;
//			}
//			insert_data(head, tail, l2->val);
//			l2 = l2->next;
//		}
//		if (extern_data != 0) {
//			insert_data(head, tail, extern_data);
//		}
//		return head;
//	}
//	void insert_data(ListNode *&head,ListNode *&tail,int val) {
//		if (head == NULL) {
//			head = new ListNode(val);
//			tail = head;
//		}
//		else {
//			ListNode* temp = new ListNode(val);
//			tail->next = temp;
//			tail = temp;
//		}
//	}
//};
//
//
///**
// * Definition for singly-linked list.
// * struct ListNode {
// *     int val;
// *     ListNode *next;
// *     ListNode(int x) : val(x), next(NULL) {}
// * };
// */
//
//#include <iostream>
//
//using namespace std;
//
//struct ListNode {
//	int val;
//	ListNode *next;
//	ListNode(int x) : val(x), next(NULL) {}
//	
//};
//
//class Solution {
//public:
//	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
//		int extern_data = 0;
//		ListNode* head = NULL;
//		ListNode* tail = NULL;
//		int val = 0;
//		while (l1 != NULL && l2 != NULL) {
//			val = l1->val + l2->val + extern_data;
//			extern_data = val / 10;
//			insert_data(head, tail, val % 10);
//			l1 = l1->next;
//			l2 = l2->next;
//		}
//		while (l1 != NULL) {
//			if (extern_data != 0) {
//				l1->val += extern_data;
//				extern_data = l1->val / 10;
//				l1->val %= 10;
//			}
//			insert_data(head, tail, l1->val);
//			l1 = l1->next;
//		}
//		while (l2 != NULL) {
//			if (extern_data != 0) {
//				l2->val += extern_data;
//				extern_data = l2->val / 10;
//				l2->val %= 10;
//			}
//			insert_data(head, tail, l2->val);
//			l2 = l2->next;
//		}
//		if (extern_data != 0) {
//			insert_data(head, tail, extern_data);
//		}
//		return head;
//	}
//	void insert_data(ListNode *&head,ListNode *&tail,int val) {
//		if (head == NULL) {
//			head = new ListNode(val);
//			tail = head;
//		}
//		else {
//			ListNode* temp = new ListNode(val);
//			tail->next = temp;
//			tail = temp;
//		}
//	}
//};

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

#include <iostream>

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}

};

class Solution {
public:
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		int extern_data = 0;
		int val = 0;
		if (l1 == NULL) {
			l1 = new ListNode(0);
		}
		ListNode* head = l1;
		if (l2 == NULL) {
			l2 = new ListNode(0);
		}
		while (l1->next != NULL && l2->next != NULL) {
			val = l1->val + l2->val + extern_data;
			extern_data = val / 10;
			l1->val = val % 10;
			l1 = l1->next;
			l2 = l2->next;
		}
		val = l1->val + l2->val + extern_data;
		extern_data = val / 10;
		l1->val = val % 10;

		while (l1->next != NULL) {
			l1 = l1->next;
			if (extern_data != 0) {
				l1->val += extern_data;
				extern_data = l1->val / 10;
				l1->val %= 10;
			}
		}

		while (l2->next != NULL) {
			l2 = l2->next;
			if (extern_data != 0) {
				l2->val += extern_data;
				extern_data = l2->val / 10;
				l2->val %= 10;
			}
			l1->next = l2;
			l1 = l2;
		}
		if (extern_data != 0) {
			if (l1->next != NULL)
				l1 = l1->next;
			insert_data(head, l1, extern_data);
		}
		return head;
	}

	void insert_data(ListNode *&head, ListNode *&tail, int val) {
		if (head == NULL) {
			head = new ListNode(val);
			tail = head;
		}
		else {
			ListNode* temp = new ListNode(val);
			tail->next = temp;
			tail = temp;
		}
	}
};