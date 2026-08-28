class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {

        if(head == NULL || left == right)
            return head;

        ListNode* curr = head;
        ListNode* prev = NULL;
        ListNode* future = NULL;

        int originalLeft = left;

        while(left != 1){
            prev = curr;
            curr = curr->next;
            left--;
        }

        ListNode* before = prev;
        ListNode* first = curr;

        int count = right - originalLeft + 1;

        while(count != 0){
            future = curr->next;
            curr->next = prev;
            prev = curr;
            curr = future;
            count--;
        }

        if(before != NULL){
            before->next = prev;
        }
        else{
            head = prev;
        }

        first->next = curr;

        return head;
    }
};