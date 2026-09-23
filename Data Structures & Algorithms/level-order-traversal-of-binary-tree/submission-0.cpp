class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> result;

        if(root == NULL) return result;

        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()) {
            int size = q.size();
            vector<int> ans;

            for(int i = 0; i < size; i++) {
                TreeNode* node = q.front();
                q.pop();

                ans.push_back(node->val);

                if(node->left != NULL) {
                    q.push(node->left);
                }

                if(node->right != NULL) {
                    q.push(node->right);
                }
            }

            result.push_back(ans);
        }

        return result;
    }
};