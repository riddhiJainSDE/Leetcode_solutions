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
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        map<TreeNode*, TreeNode*> par;

        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty())
        {
            TreeNode* node=q.front();
            q.pop();

            if(node->left != NULL)
            {
                par[node->left]=node;
                q.push(node->left);
            }

            if(node->right != NULL)
            {
                par[node->right]=node;
                q.push(node->right);
            }



        }

        q.push(target);
        int dis=0;
        vector<int> vis(501);
        vis[target->val]=1;
        while(dis<k)
        {
            

            int s=q.size();
            for(int i=0;i<s;i++)
            {
                TreeNode* node = q.front();
                q.pop();

                if(par.find(node)!=par.end() && vis[par[node]->val]==0)
                {
                    vis[par[node]->val]=1;
                    q.push(par[node]);
                }

                if(node->left != NULL && vis[node->left->val]==0)
                {
                    vis[node->left->val]=1;
                    q.push(node->left);
                }

                if(node->right !=NULL && vis[node->right->val]==0)
                {
                    vis[node->right->val]=1;
                    q.push(node->right);
                }
            }
            dis++;

        }
        vector<int> ans;
        while(!q.empty())
        {
            ans.push_back(q.front()->val);
            q.pop();
        }

        return ans;


    }
};