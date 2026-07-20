class Solution {
public:
    unordered_map<int,int> mp;
    int idx;

    TreeNode* build(vector<int>& inorder, vector<int>& postorder, int l, int r) {
        if (l > r) return nullptr;

        TreeNode* root = new TreeNode(postorder[idx--]);
        int pos = mp[root->val];

        root->right = build(inorder, postorder, pos + 1, r);
        root->left = build(inorder, postorder, l, pos - 1);

        return root;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        for (int i = 0; i < inorder.size(); i++)
            mp[inorder[i]] = i;

        idx = postorder.size() - 1;
        return build(inorder, postorder, 0, inorder.size() - 1);
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna