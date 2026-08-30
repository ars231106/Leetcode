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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if(l1 == NULL && l2 == NULL){
            return NULL;
        }

        if(l1 == NULL){
            return l2;
        }

        if(l2 == NULL){
            return l1;
        }

        ListNode* head1 = l1;
        ListNode* head2 = l2;

        ListNode* sumhead = NULL;
        ListNode* sumtemp = NULL;

        int carry = 0;

        while(head1 != NULL || head2 != NULL || carry != 0){
            int orgsum = carry;

            if(head1 != NULL){
                orgsum += head1 -> val ;
                head1 = head1 -> next;
            }

            if(head2 != NULL){
                orgsum += head2 -> val ;
                head2 = head2 -> next;
            }

            int sum = orgsum % 10;
            carry = orgsum / 10;

            ListNode* newNode = new ListNode(sum);

            if(sumhead == NULL){
                sumhead = newNode;
                sumtemp = newNode;
            }

            else{
                sumtemp -> next = newNode;
                sumtemp = newNode;
            }
        }

        return sumhead;
        
    }
};