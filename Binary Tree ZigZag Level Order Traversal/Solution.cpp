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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> result; 
        if(!root)
            return result; 
        queue<TreeNode*> nodeQueue; 
        nodeQueue.push(root);
        bool isReverse = false;
        while(!nodeQueue.empty()) {
            int size = nodeQueue.size(); 
            vector<int> subResult; 
            while(size--) {
                TreeNode* node = nodeQueue.front();
                nodeQueue.pop(); 
                subResult.push_back(node->val);
                if(node->left)
                    nodeQueue.push(node->left);
                if(node->right)
                    nodeQueue.push(node->right);
            }
            if(isReverse) 
                std::reverse(subResult.begin(), subResult.end());
            isReverse = isReverse ? false : true;
            result.push_back(subResult);
        }
        return result;
    }
};