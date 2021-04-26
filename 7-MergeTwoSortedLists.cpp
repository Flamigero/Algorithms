/*
Merge two sorted linked lists and return it as a sorted list. The list should be made by splicing together the nodes of the first two lists.

Input: l1 = [1,2,4], l2 = [1,3,4]
Output: [1,1,2,3,4,4]
*/
#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int data)
    {
        this->val = data;
        this->next = NULL;
    }
};
 
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(l1 == NULL) return l2;
        if(l2 == NULL) return l1;

        ListNode* returnList = NULL;

        if(l1->val >= l2->val)
        {
            returnList = l2;
            l2 = l2->next;
        }
        else{
            returnList = l1;
            l1 = l1->next;
        }

        ListNode* temp = returnList;
        while (l1 && l2)
        {
            if(l1->val >= l2->val)
            {
                temp->next = l2;
                l2 = l2->next;
            }
            else{
                temp->next = l1;
                l1 = l1->next;
            }
            temp = temp->next;
        }

        if(l1)
            temp->next = l1;
        else
            temp->next = l2;

        return returnList;
    }
};

int main()
{

    Solution s;
    ListNode l1(1);
    ListNode l2(2);

    ListNode *l3 = s.mergeTwoLists(&l1, &l2);

    return 0;

}