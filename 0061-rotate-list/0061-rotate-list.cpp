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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == NULL || head -> next == NULL){
            return head;
        }

        int n = 0;
        ListNode* temp = head;
        while(temp != NULL){
            n = n + 1;
            temp = temp -> next;
        }

        k = k % n;

        for(int i = 1; i<=k; i++){
            ListNode* p = head;
            ListNode* q = head;

            while(p -> next != NULL){
                q = p;
                p = p -> next;
            }

            q -> next = NULL;
            p -> next = head;
            head = p;
        }

        return head;
    }
};