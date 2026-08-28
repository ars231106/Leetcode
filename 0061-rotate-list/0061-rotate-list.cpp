class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {

        if(head == NULL || head->next == NULL)
            return head;

        int n = 0;
        ListNode* temp = head;

        while(temp != NULL){
            n++;
            temp = temp->next;
        }

        k = k % n;

        for(int i = 0; i < k; i++){

            ListNode* p = head;
            ListNode* q = head;

            while(p->next != NULL){
                p = p->next;
            }

            while(q->next != p){
                q = q->next;
            }

            q->next = NULL;
            p->next = head;
            head = p;
        }

        return head;
    }
};