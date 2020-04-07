/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> largestValues(TreeNode* root) {
        // <1> 
        // <3,2> 
        // <5,3,9>  
        vector<int> result;
        if(!root)
            return result;
        queue<TreeNode*> nodeQueue; 
        nodeQueue.push(root);
        while(!nodeQueue.empty()) {
            int size = nodeQueue.size(); 
            int maximumNumber = INT_MIN;
            while(size--) {
                TreeNode* node = nodeQueue.front();
                nodeQueue.pop();
                if(maximumNumber < node->val)
                    maximumNumber = node->val;
                if(node->left)
                    nodeQueue.push(node->left);
                if(node->right)
                    nodeQueue.push(node->right);   
            }
            result.push_back(maximumNumber);
        }
        return result;
        
    }
};