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
    vector<int> rightSideView(TreeNode* root) {
        vector<int>ans;
        if(root==NULL) return ans;
        queue<TreeNode*>st;
        st.push(root);
        while(!st.empty()){
            int n=st.size();
            
            for(int i=0;i<n;i++){

                TreeNode* node=st.front();
            st.pop();
                if(i==n-1){
                    ans.push_back(node->val);
                }
                if(node->left){
                    st.push(node->left);
                }

                if(node->right){
                    st.push(node->right);
                }
            }
        }
        return ans;
    }
};
