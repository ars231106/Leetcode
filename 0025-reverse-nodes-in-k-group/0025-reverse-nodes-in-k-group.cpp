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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* first = new ListNode(0);
        first -> next = head;
        head = first;

        while(first -> next != NULL){
            ListNode* check = first;
            int x = k;

            while(x && check->next != NULL){
                check = check->next;
                x--;
            }
            
            if(x != 0){
                break;
            }

            x = k;
            ListNode* second = first -> next;
            ListNode* prev = first;
            ListNode* curr = first -> next;
            ListNode* future = NULL;

            while(x && curr != NULL){
                future = curr -> next;
                curr -> next = prev;
                prev = curr;
                curr = future;
                x--;
            }

            first -> next = prev;
            second -> next = curr;
            first = second;
        }

        first = head;
        head = head -> next;
        delete first;

        return head;
    }
};