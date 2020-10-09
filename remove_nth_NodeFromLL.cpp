// Time Complexity : O(N)
// Space Complexity : O(1)
// Did this code successfully run on Leetcode : Yes
// Any problem you faced while coding this : No


// Your code here along with comments explaining your approach

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *slow=head,*fast=head;
        int count=0;
        
        while (slow!=NULL && count<n) { //move the pointer n steps forward
            slow=slow->next;
            count++;
        }
        if(slow==NULL) //remove the first node 
            return fast->next;
        
        while (slow!=NULL && slow->next!=NULL) {  
            slow=slow->next;
            fast=fast->next;
        }
        
        if (fast!=NULL && fast->next!=NULL) {
        ListNode *temp=fast->next->next;
        fast->next=temp;
        }
        
        return head;
    }
};