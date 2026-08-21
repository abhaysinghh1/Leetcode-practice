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
    int widthOfBinaryTree(TreeNode* root) {
        if(root==nullptr)return 0;
        int maxW=0;

        queue<pair<TreeNode*,long long>>q;
        q.push({root,0});
        while(!q.empty()){
            int len=q.size();
            long long l = q.front().second;
            long long r = q.back().second;

            maxW=max(maxW,(int)(r-l+1));
            for(int i=0;i<len;i++){
                 auto [node,idx]=q.front();
                 q.pop();
                 if(node->left!=nullptr){
                    q.push({node->left,(int)(2*idx+1)});
                 }
                 if(node->right!=nullptr){
                    q.push({node->right,(int)(2*idx+2)});
                 }
            }
        }
        return maxW;
        
    }
};