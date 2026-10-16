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
    vector<int> largestValues(TreeNode* root) {
        if(root==nullptr) return {};
          queue<TreeNode*>q;
        q.push(root);
       vector<int>ans;
       while(!q.empty()){
        int n=q.size();
        vector<int>temp;
        for(int i=0;i<n;i++){
            TreeNode* node=q.front();
            q.pop();
            temp.push_back(node->val);
             if(node->left!=nullptr){
                    q.push(node->left);
                   
                } 
                if(node->right!=nullptr){
                    q.push(node->right);
                   
                }
        }
        int maxi=*max_element(temp.begin(),temp.end());
        ans.push_back(maxi);

       }
       return ans;
        
    }
};