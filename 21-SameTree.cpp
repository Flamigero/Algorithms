/*
Given the roots of two binary trees p and q, write a function to check if they are the same or not.
Two binary trees are considered the same if they are structurally identical, and the nodes have the same value.

Example 1:
Input: p = [1,2,3], q = [1,2,3]
Output: true
*/
#include <iostream>
using namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p == NULL && q == NULL)
            return true;
        
        if((p && q==NULL) || (p==NULL && q))
            return false;

        if(p->val != q->val)
            return false;

        bool left = isSameTree(p->left, q->left);
        bool right = isSameTree(p->right, q->right);

        return left && right;
    }
};

int main()
{

    Solution s;
    TreeNode *p1 = new TreeNode(1);
    TreeNode *p2 = new TreeNode(2);
    TreeNode *p3 = new TreeNode(3);
    TreeNode *q1 = new TreeNode(1);
    TreeNode *q2 = new TreeNode(2);
    TreeNode *q3 = new TreeNode(3);
    p1->left = p2;
    p1->right = p3;
    q1->left = q2;
    q1->right = q3;

    cout << s.isSameTree(p1, q1) << endl;

    return 0;

}