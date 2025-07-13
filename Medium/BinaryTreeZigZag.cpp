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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        vector<vector<int>> ans;
        if(root==NULL) return ans;
        while(!q.empty())
        {
            vector<int> level;
            int size=q.size();

            for(int i=0;i<size;i++)
            {
                TreeNode* front=q.front();
                level.push_back(front->val);
                q.pop();


                    if(front->left != NULL) q.push(front->left);
                    if(front->right != NULL) q.push(front->right);


                
            }

            ans.push_back(level);
        }

        for(int i=0;i<ans.size();i++)
        {
            if(i%2 !=0)
            {
                
                reverse(ans[i].begin(), ans[i].end());
            }

            
        }

        return ans;
    }
};