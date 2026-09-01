/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void preorderq(TreeNode* q, string &q_q){
        if(q == NULL){
            q_q = q_q + "N";
            return;
        }

        q_q = q_q + to_string(q -> val);
        preorderq(q -> left, q_q);
        preorderq(q -> right, q_q);
    }
    
    void preorderp(TreeNode* p, string &p_p){
        if(p == NULL){
             p_p = p_p + "N";
             return;
        }

        p_p = p_p + to_string(p -> val);
        preorderp(p -> left, p_p);
        preorderp(p -> right, p_p);
    }

    bool isSameTree(TreeNode* p, TreeNode* q) {
        string q_q;
        string p_p;

        preorderp(p, p_p);
        preorderq(q, q_q);

        if(p_p == q_q){
            return true;
        }

        return false;
    }
};