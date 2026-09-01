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
    string preorderq(TreeNode* q){
        if(q == NULL){
            return "N";
        }

        return to_string(q -> val) + preorderp(q -> left) + preorderp(q -> right);
    }
    
    string preorderp(TreeNode* p){
        if(p == NULL){
            return "N";
        }

        return to_string(p -> val) + preorderp(p -> left) + preorderp(p -> right);
    }

    bool isSameTree(TreeNode* p, TreeNode* q) {
        string p_p = preorderp(p);
        string q_q = preorderq(q);

        if(p_p == q_q){
            return true;
        } 

        return false;
    }
};