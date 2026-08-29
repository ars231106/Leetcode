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
    bool hasCycle(ListNode* head) {
        ListNode* temp = head;
        vector<ListNode*> visited;

        while(temp != NULL){
            for(int i = 0; i<visited.size(); i++) {
                if(visited[i] == temp){
                    return true;
                }
            }
            visited.push_back(temp);
            temp = temp -> next;
        }

        return false;
    }
};