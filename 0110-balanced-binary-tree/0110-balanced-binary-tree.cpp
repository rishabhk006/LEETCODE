class Solution {
public:
    int height(TreeNode* root) {
        if (!root)
            return 0;

        int left = height(root->left);
        if (left == -1)
            return -1;

        int right = height(root->right);
        if (right == -1)
            return -1;

        if (abs(left - right) > 1)
            return -1;

        return max(left, right) + 1;
    }

    bool isBalanced(TreeNode* root) {
        return height(root) != -1;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna