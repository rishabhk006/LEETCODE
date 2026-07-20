class Solution {
public:
    unordered_map<int, int> mp;
    int idx = 0;

    TreeNode* build(vector<int>& preorder, vector<int>& inorder, int l, int r) {
        if (l > r) return nullptr;

        TreeNode* root = new TreeNode(preorder[idx++]);
        int pos = mp[root->val];

        root->left = build(preorder, inorder, l, pos - 1);
        root->right = build(preorder, inorder, pos + 1, r);

        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for (int i = 0; i < inorder.size(); i++)
            mp[inorder[i]] = i;

        return build(preorder, inorder, 0, inorder.size() - 1);
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna