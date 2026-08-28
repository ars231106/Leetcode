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
    ListNode* Reverse(ListNode* curr, ListNode* prev, ListNode* future){
        if(curr == NULL){
            return prev;
        }
        future = curr -> next;
        curr -> next = prev;
        ListNode* rev = Reverse(future, curr, future);
        return rev;
    }
    ListNode* reverseList(ListNode* head) {
        head = Reverse(head, NULL, NULL);
        return head;
    }
};