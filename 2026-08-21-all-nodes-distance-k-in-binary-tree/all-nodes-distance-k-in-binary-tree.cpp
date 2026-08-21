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
    void inorder(TreeNode*root,unordered_map<TreeNode*,TreeNode*>&mpp){
        if(root==nullptr) return;
        if(root->left!=nullptr){
            mpp[root->left]=root;
        }
        inorder(root->left,mpp);
        if(root->right!=nullptr){
            mpp[root->right]=root;
        }
        inorder(root->right,mpp);
        return;
    }
    void BFS(TreeNode* target, vector<int>&ans,int k,unordered_map<TreeNode*,TreeNode*>&mpp){
        
        queue<TreeNode*>q;
        q.push(target);
        unordered_set<int>st;
        st.insert(target->val);
        while(!q.empty()){
            int len=q.size();
            if(k==0) break;
            for(int i=0;i<len;i++){
                TreeNode* curr=q.front();
                q.pop();
                if(curr->left!=nullptr && !st.count(curr->left->val)){
                    q.push(curr->left);
                    st.insert(curr->left->val);
                }
                if(curr->right!=nullptr && !st.count(curr->right->val)){
                    q.push(curr->right);
                    st.insert(curr->right->val);
                }
                if(mpp.count(curr)&&!st.count(mpp[curr]->val)){
                    q.push(mpp[curr]);
                    st.insert(mpp[curr]->val);
                }
            }
            k--;
        }
        
        while(!q.empty()){
            ans.push_back(q.front()->val);
            q.pop();
        }

    }
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*,TreeNode*>mpp;
        vector<int>ans;
        inorder(root,mpp);
        BFS(target,ans,k,mpp);
        return ans;
        
    }
};