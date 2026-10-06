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
    void inorder(TreeNode* root, vector<int>&list){
        if(root == NULL){
            return;
        }

        inorder(root -> left, list);
        list.push_back(root -> val);
        inorder(root -> right, list);
    }

    vector<int> merge(vector<int>& list1, vector<int>& list2){
        int left = 0;
        int right = 0;

        vector<int> merged;

        while(left < list1.size() && right < list2.size()){
            if(list1[left] <= list2[right]){
                merged.push_back(list1[left]);
                left++;
            }
            else{
                merged.push_back(list2[right]);
                right++;
            }
        }

        while(left < list1.size()){
            merged.push_back(list1[left]);
            left++;
        }

        while(right < list2.size()){
            merged.push_back(list2[right]);
            right++;
        }

        return merged;
    }

    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int> inorderone;
        vector<int> inordertwo;

        inorder(root1, inorderone);
        inorder(root2, inordertwo);

        vector<int> merged = merge(inorderone, inordertwo);

        return merged;
    }
};