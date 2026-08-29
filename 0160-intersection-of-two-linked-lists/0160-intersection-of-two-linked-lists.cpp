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
        int count1 = 0, count2 = 0;
        ListNode* temp1 = headA;

        while(temp1 != NULL){
            count1++;
            temp1 = temp1-> next;
        }

        ListNode* temp2 = headB;

        while(temp2 != NULL){
            count2++;
            temp2 = temp2 -> next;
        }

        temp1 = headA;
        temp2 = headB;

        if(count1 > count2){
            while(count1 != count2){
                temp1 = temp1 -> next;
                count1--;
            }
        }

        if(count1 < count2){
            while(count2 != count1){
                temp2 = temp2 -> next;
                count2--;
            }
        }

        if(count1 == count2){
            while(!(temp1 == temp2)){
                temp1 = temp1 -> next;
                temp2 = temp2 -> next;
            }

            return temp2;
        }

        return NULL;
    }
};