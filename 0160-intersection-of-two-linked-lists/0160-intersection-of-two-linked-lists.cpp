/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
       ListNode* temp = headA;
       while(temp -> next != NULL){
           temp = temp -> next;
       }

       temp -> next = headA;

       ListNode* slow = headB;
       ListNode* fast = headB;

       while(fast != NULL && fast -> next != NULL){
            slow = slow -> next;
            fast = fast -> next -> next;

            if(slow == fast){
                break;
            }
       }

       if(fast == NULL || fast -> next == NULL){
           temp -> next = NULL;
           return NULL;
       }

       slow = headB;

       while(slow != fast){
          slow = slow -> next;
          fast = fast -> next;
       }

       temp -> next = NULL;

       return slow;
    }
};