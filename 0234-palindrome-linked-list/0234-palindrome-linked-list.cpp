class Solution {
public:
    ListNode* reverse(ListNode* curr, ListNode* prev){
        ListNode* future = NULL;

        while(curr != NULL){
            future = curr->next;
            curr->next = prev;
            prev = curr;
            curr = future;
        }

        return prev;
    }

    bool isPalindrome(ListNode* head) {

        if(head == NULL || head->next == NULL)
            return true;

        int count = 0;
        ListNode* temp = head;

        while(temp != NULL){
            count++;
            temp = temp->next;
        }

        int partition = count / 2;

        temp = head;

        while(partition != 1){
            temp = temp->next;
            partition--;
        }

        ListNode* p;

        if(count % 2 == 0){
            p = temp->next;
            temp->next = NULL;
        }
        else{
            p = temp->next->next;
            temp->next = NULL;
        }

        head = reverse(head, NULL);

        temp = head;

        while(temp != NULL && p != NULL){
            if(temp->val != p->val)
                return false;

            temp = temp->next;
            p = p->next;
        }

        return true;
    }
};