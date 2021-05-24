/*
You are given two non-empty linked lists representing two non-negative integers. 
The digits are stored in reverse order, and each of their nodes contains a single digit. 
Add the two numbers and return the sum as a linked list.
You may assume the two numbers do not contain any leading zero, except the number 0 itself.

Example 1:
Input: l1 = [2,4,3], l2 = [5,6,4]
Output: [7,0,8]
Explanation: 342 + 465 = 807.
*/
#include <iostream>
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0;
        ListNode *head = new ListNode();
        ListNode *temp = head;

        while (l1!=NULL || l2!=NULL || carry!=0)
        {
            int sum;
            if(l1 && l2) sum = l1->val + l2->val + carry;
            else if(l1 && !l2) sum = l1->val + carry;
            else if(!l1 && l2) sum = l2->val + carry;
            else sum = carry;
            carry = sum/10;
            temp->next = new ListNode(sum%10);
            temp = temp->next;

            if(l1) l1 = l1->next;
            if(l2) l2 = l2->next;
        }

        return head->next;
    }
};

int main()
{

    Solution s;
    ListNode *l1 = new ListNode(9);
    ListNode *l2 = new ListNode(9);
    l1->next = l2;

    ListNode *p1 = new ListNode(5);
    ListNode *p2 = new ListNode(6);
    ListNode *p3 = new ListNode(4);
    p1->next = p2;
    p2->next = p3;

    ListNode *result = s.addTwoNumbers(l1, p1);
    while (result != NULL)
    {
        cout << result->val << " ";
        result = result->next;
    }
    cout << endl;

    return 0;

}