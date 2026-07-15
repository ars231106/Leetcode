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
    ListNode* deleteDuplicates(ListNode* head) {
        while(head != NULL && head -> next != NULL && head -> val == head -> next -> val){
            int val = head -> val;
            while(head != NULL && head -> val == val){
                head = head -> next;
            }
        }

        if(head == NULL) {
            return NULL;
        }

        ListNode* prev = head;
        ListNode* p = head -> next;


        while(p!= NULL && p->next!=NULL){
            if(p -> next != NULL && p -> val == p -> next -> val){
                int val = p -> val;
                
                while(p != NULL && p -> val == val){
                     p = p -> next;
                }
                prev -> next = p;
            }

            else{
                prev = p;
                p = p -> next;
            }
        }

        return head;

    }
};